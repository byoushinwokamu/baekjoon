#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

void usage_err()
{
  cout << "Usage: tester -r <testcase_number> : run tc (show in & out)\n";
  cout << "              -a                   : run all tcs (show out only)\n";
  cout << "              -n <testcase_number> : add tc\n";
  cout << "              -c                   : clear tcs\n";
  exit(1);
}

bool file_exists(const string &name)
{
  return fs::exists(name);
}

// 파일의 마지막 문자가 개행인지 확인하고, 아니면 개행을 출력해주는 함수
void ensure_newline_on_console(const string &filename)
{
  ifstream ifs(filename, ios::binary | ios::ate); // 파일을 끝에서부터 염
  if (!ifs.is_open()) return;

  auto size = ifs.tellg();
  if (size == 0)
  {
    // 파일이 비어있으면 그냥 개행 한번 해줌
    cout << endl;
    return;
  }

  ifs.seekg(-1, ios::end); // 맨 뒤에서 1바이트 앞으로 이동
  char last_char;
  ifs.get(last_char);

  // 마지막 글자가 개행이 아니면 개행 추가
  if (last_char != '\n')
  {
    cout << endl; // 화면에 % 또는 섞여 나오지 않게 줄바꿈
  }
}

void run_testcase(const string &num, bool is_batch)
{
  string input_file = "testcase_" + num + ".txt";
  string result_file = "testresult_" + num + ".txt";
  string temp_output = ".temp_output";

  if (!file_exists(input_file))
  {
    cerr << "Error: " << input_file << " does not exist.\n";
    return;
  }

  cout << "[ Run Testcase " << num << " ]" << endl;

  // 1. 실행 및 임시 저장
  string cmd_run = "./result < " + input_file + " > " + temp_output;
  int ret = system(cmd_run.c_str());

  if (ret != 0)
  {
    cout << "Runtime Error or execution failed." << endl;
    system(("rm -f " + temp_output).c_str());
    return;
  }

  // 2. 결과 파일 조립 (Input + Output)
  ofstream res(result_file);
  res << "[Input]\n";
  res.close();

  string cmd_append_in = "cat " + input_file + " >> " + result_file;
  system(cmd_append_in.c_str());

  res.open(result_file, ios::app);
  res << "\n[Output]\n";
  res.close();

  string cmd_append_out = "cat " + temp_output + " >> " + result_file;
  system(cmd_append_out.c_str());

  // 3. 콘솔 출력 및 줄바꿈 보정
  string file_to_show = is_batch ? temp_output : result_file;

  string cmd_show = "cat " + file_to_show;
  system(cmd_show.c_str());

  // 핵심: 방금 출력한 파일의 끝이 개행이 아니면 개행을 쏴줌
  ensure_newline_on_console(file_to_show);

  // 4. 정리
  system(("rm -f " + temp_output).c_str());

  cout << "--------------------------------------------------" << endl;
}

int main(int argc, char **argv)
{
  if (argc < 2 || argc > 3) usage_err();
  if (strlen(argv[1]) != 2 || argv[1][0] != '-') usage_err();

  string num;
  if (argc == 3) num = argv[2];

  switch (argv[1][1])
  {
  case 'r': // Run single
    if (argc != 3) usage_err();
    run_testcase(num, false);
    break;

  case 'a': // Run all
  {
    if (argc != 2) usage_err();

    vector<int> cases;
    for (const auto &entry : fs::directory_iterator("."))
    {
      string fname = entry.path().filename().string();
      if (fname.rfind("testcase_", 0) == 0 && fname.find(".txt") != string::npos)
      {
        try
        {
          string s_num = fname.substr(9, fname.length() - 13);
          cases.push_back(stoi(s_num));
        }
        catch (...)
        {
          continue;
        }
      }
    }

    sort(cases.begin(), cases.end());

    if (cases.empty())
    {
      cout << "No testcases found." << endl;
      return 0;
    }

    for (size_t i = 0; i < cases.size(); ++i)
    {
      run_testcase(to_string(cases[i]), true);

      if (i < cases.size() - 1)
      {
        // 다음 케이스 넘어가기 전 안내 메시지 (바로 엔터 대기)
        // run_testcase 안에서 이미 구분선이 출력되었으므로 여기서는 대기만 함
        cout << "Press Enter to run next testcase...";
        cin.get();
        cout << endl; // 입력받은 엔터에 대한 줄바꿈 처리는 명시적으로
      }
    }
    break;
  }

  case 'n': // Add
  {
    if (argc != 3) usage_err();
    string filename = "testcase_" + num + ".txt";

    if (file_exists(filename))
    {
      cerr << "Error: " << filename << " already exists.\n";
      exit(1);
    }

    cout << "Enter input for " << filename << " (Press Ctrl+D to finish):" << endl;

    ofstream file(filename);
    if (!file.is_open())
    {
      cerr << "Error: Could not create file.\n";
      exit(1);
    }

    char ch;
    while (cin.get(ch))
    {
      file << ch;
    }
    file.close();
    cout << "\nSaved " << filename << endl;
    break;
  }

  case 'c': // Clear
    if (argc != 2) usage_err();
    cout << "Clearing all testcase_*.txt and testresult_*.txt..." << endl;
    system("rm -f testcase_*.txt testresult_*.txt .temp_output");
    cout << "Done." << endl;
    break;

  default:
    usage_err();
  }

  return 0;
}