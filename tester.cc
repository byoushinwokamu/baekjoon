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
  cout << "Usage:\n";
  cout << "  tester run           : run all testcases\n";
  cout << "  tester run <num>     : run specific testcase\n";
  cout << "  tester add <num>     : add testcase (Input -> EOF -> Desired -> EOF)\n";
  cout << "  tester list          : show list of testcase numbers\n";
  cout << "  tester clear         : remove all test files\n";
  cout << "  tester clear <num>   : remove specific test files\n";
  exit(1);
}

bool file_exists(const string &name)
{
  return fs::exists(name);
}

// 현재 디렉토리의 모든 testcase 번호를 가져와 정렬하여 반환
vector<int> get_testcases()
{
  vector<int> cases;
  for (const auto &entry : fs::directory_iterator("."))
  {
    string fname = entry.path().filename().string();
    if (fname.rfind("testcase_", 0) == 0 && fname.find(".txt") != string::npos)
    {
      try
      {
        // "testcase_" (9글자) 이후부터 ".txt" 앞까지 숫자 추출
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
  return cases;
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
  string answer_file = "testanswer_" + num + ".txt";
  string result_file = "testresult_" + num + ".txt";
  string temp_output = ".temp_output";

  if (!file_exists(input_file))
  {
    cerr << "Error: " << input_file << " does not exist.\n";
    return;
  }

  cout << "[ Run Testcase " << num << " ]" << endl;

  // 1. 실행
  string cmd_run = "./result < " + input_file + " > " + temp_output;
  int ret = system(cmd_run.c_str());

  if (ret != 0)
  {
    cout << "Runtime Error or execution failed." << endl;
    system(("rm -f " + temp_output).c_str());
    return;
  }

  // 2. 결과 파일 조립
  ofstream res(result_file);

  // [Input]
  res << "[Input]\n";
  res.close();
  string cmd_append_in = "cat " + input_file + " >> " + result_file;
  system(cmd_append_in.c_str());

  // [Desired Output]
  res.open(result_file, ios::app);
  res << "\n[Desired Output]\n";
  res.close();

  if (file_exists(answer_file))
  {
    string cmd_append_ans = "cat " + answer_file + " >> " + result_file;
    system(cmd_append_ans.c_str());
  }

  // [Output]
  res.open(result_file, ios::app);
  res << "\n[Output]\n";
  res.close();
  string cmd_append_out = "cat " + temp_output + " >> " + result_file;
  system(cmd_append_out.c_str());

  // 3. 콘솔 출력
  string cmd_show = "cat " + result_file;
  system(cmd_show.c_str());

  // 4. 줄바꿈 보정
  ensure_newline_on_console(temp_output);

  // 5. 정리
  system(("rm -f " + temp_output).c_str());

  cout << "--------------------------------------------------" << endl;
}

int main(int argc, char **argv)
{
  if (argc < 2) usage_err();

  string command = argv[1];
  string num = "";
  if (argc >= 3) num = argv[2];

  if (command == "run")
  {
    if (argc == 3)
    {
      run_testcase(num);
    }
    else
    {
      vector<int> cases = get_testcases(); // 함수 재사용

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
    }
  }
  else if (command == "add")
  {
    if (argc != 3) usage_err();

    string tc_file = "testcase_" + num + ".txt";
    string ans_file = "testanswer_" + num + ".txt";

    if (file_exists(tc_file))
    {
      cerr << "Error: " << tc_file << " already exists.\n";
      exit(1);
    }

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

    cin.clear();
    clearerr(stdin);

    cout << "\n[Input] Saved." << endl;
    cout << "Enter [Desired Output] for " << ans_file << " (Press Ctrl+D to finish):" << endl;

    ofstream a_file(ans_file);
    if (!a_file.is_open())
    {
      cerr << "Error: Could not create file.\n";
      exit(1);
    }
    while (cin.get(ch)) a_file << ch;
    a_file.close();

    cout << "\n[Desired Output] Saved. Testcase " << num << " created." << endl;
  }
  else if (command == "list")
  {
    // 목록 출력 기능 구현
    vector<int> cases = get_testcases();

    if (cases.empty())
    {
      cout << "No testcases found." << endl;
    }
    else
    {
      cout << "Testcase list: ";
      for (size_t i = 0; i < cases.size(); ++i)
      {
        cout << cases[i] << (i == cases.size() - 1 ? "" : " ");
      }
      cout << endl;
    }
  }
  else if (command == "clear")
  {
    if (argc == 3)
    {
      string tc = "testcase_" + num + ".txt";
      string ta = "testanswer_" + num + ".txt";
      string tr = "testresult_" + num + ".txt";

      cout << "Removing testcase " << num << " files..." << endl;
      string cmd = "rm -f " + tc + " " + ta + " " + tr;
      system(cmd.c_str());
      cout << "Done." << endl;
    }
    else
    {
      cout << "Clearing ALL testcase_*, testanswer_*, testresult_* ..." << endl;
      system("rm -f testcase_*.txt testanswer_*.txt testresult_*.txt .temp_output");
      cout << "Done." << endl;
    }
  }
  else
  {
    usage_err();
  }

  return 0;
}