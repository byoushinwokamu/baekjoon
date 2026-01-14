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
  cout << "Usage: tester -r <testcase_number> : run tc\n";
  cout << "              -a                   : run all tcs\n";
  cout << "              -n <testcase_number> : add tc (Input -> EOF -> Desired Output -> EOF)\n";
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
  ifstream ifs(filename, ios::binary | ios::ate);
  if (!ifs.is_open()) return;

  auto size = ifs.tellg();
  if (size == 0)
  {
    cout << endl;
    return;
  }

  ifs.seekg(-1, ios::end);
  char last_char;
  ifs.get(last_char);

  if (last_char != '\n')
  {
    cout << endl;
  }
}

void run_testcase(const string &num)
{
  string input_file = "testcase_" + num + ".txt";
  string answer_file = "testanswer_" + num + ".txt"; // Desired Output 파일
  string result_file = "testresult_" + num + ".txt";
  string temp_output = ".temp_output";

  if (!file_exists(input_file))
  {
    cerr << "Error: " << input_file << " does not exist.\n";
    return;
  }

  cout << "[ Run Testcase " << num << " ]" << endl;

  // 1. 실제 프로그램 실행 (./result < testcase.txt > .temp_output)
  string cmd_run = "./result < " + input_file + " > " + temp_output;
  int ret = system(cmd_run.c_str());

  if (ret != 0)
  {
    cout << "Runtime Error or execution failed." << endl;
    system(("rm -f " + temp_output).c_str());
    return;
  }

  // 2. testresult 파일 조립
  ofstream res(result_file);

  // [Input] 섹션
  res << "[Input]\n";
  res.close();
  string cmd_append_in = "cat " + input_file + " >> " + result_file;
  system(cmd_append_in.c_str());

  // [Desired Output] 섹션
  res.open(result_file, ios::app);
  res << "\n[Desired Output]\n";
  res.close();

  if (file_exists(answer_file))
  {
    string cmd_append_ans = "cat " + answer_file + " >> " + result_file;
    system(cmd_append_ans.c_str());
  }
  else
  {
    // 정답 파일이 없는 경우 (그냥 비워둠)
    // res.open(result_file, ios::app); res << "(None)\n"; res.close();
  }

  // [Output] 섹션 (Actual Output)
  res.open(result_file, ios::app);
  res << "\n[Output]\n";
  res.close();
  string cmd_append_out = "cat " + temp_output + " >> " + result_file;
  system(cmd_append_out.c_str());

  // 3. 콘솔 출력 (파일 내용을 그대로 보여줌)
  // -r, -a 모두 동일하게 상세 내용을 보여달라고 하셨으므로 분기 제거
  string cmd_show = "cat " + result_file;
  system(cmd_show.c_str());

  // 4. 마지막 줄바꿈 보정 (Actual Output 끝에 개행 없으면 ----랑 겹치므로)
  ensure_newline_on_console(temp_output);

  // 5. 임시 파일 정리
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
    run_testcase(num);
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
      run_testcase(to_string(cases[i]));

      if (i < cases.size() - 1)
      {
        cout << "Press Enter to run next testcase...";
        cin.get();
        cout << endl;
      }
    }
    break;
  }

  case 'n': // Add new (Input -> EOF -> Desired -> EOF)
  {
    if (argc != 3) usage_err();
    string tc_file = "testcase_" + num + ".txt";
    string ans_file = "testanswer_" + num + ".txt";

    if (file_exists(tc_file))
    {
      cerr << "Error: " << tc_file << " already exists.\n";
      exit(1);
    }

    // 1. Input 입력
    cout << "Enter [Input] for " << tc_file << " (Press Ctrl+D to finish):" << endl;
    ofstream file(tc_file);
    if (!file.is_open())
    {
      cerr << "Error: Could not create file.\n";
      exit(1);
    }
    char ch;
    while (cin.get(ch)) file << ch;
    file.close();

    // EOF 상태 초기화 (매우 중요)
    cin.clear();
    clearerr(stdin); // 일부 환경 호환성을 위해 추가

    cout << "\n[Input] Saved." << endl;
    cout << "Enter [Desired Output] for " << ans_file << " (Press Ctrl+D to finish):" << endl;

    // 2. Desired Output 입력
    ofstream a_file(ans_file);
    if (!a_file.is_open())
    {
      cerr << "Error: Could not create file.\n";
      exit(1);
    }
    while (cin.get(ch)) a_file << ch;
    a_file.close();

    cout << "\n[Desired Output] Saved. Testcase " << num << " created." << endl;
    break;
  }

  case 'c': // Clear
    if (argc != 2) usage_err();
    cout << "Clearing all testcase_*, testanswer_*, testresult_* ..." << endl;
    // testanswer_*.txt 삭제 추가
    system("rm -f testcase_*.txt testanswer_*.txt testresult_*.txt .temp_output");
    cout << "Done." << endl;
    break;

  default:
    usage_err();
  }

  return 0;
}