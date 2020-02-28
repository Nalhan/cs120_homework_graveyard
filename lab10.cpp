/*
Nathan Park
4/5/15
Exercise 10.1
*/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class studentype {
private:
  int id;
  int grade[3];
  double avg;
  int sum;
public:
  void PrintGrade(double, double);
  void InputData(int, int []);
  int GetAvg(void);
};

int main(){
  ifstream input_file;
  input_file.open("grades.txt");
  
  if (!input_file.is_open())
    cout << "Failed to open file, closing" << endl;
  
  studentype student[128];
  int i = 0;
  int id = 0;
  int grade[3] = {0,0,0};
  double avg_sum = 0, mean = 0, sqmean_sum = 0, stdev = 0;
  while (!input_file.eof()){
    input_file >> id >> grade[0] >> grade[1] >> grade[2];
    
    student[i].InputData(id, grade);
    avg_sum = avg_sum + student[i].GetAvg();
    i++;
  }
  
  mean = avg_sum / (i-1);
  int j;
  
  for(j = 0; j < i; ++j){
    sqmean_sum = sqmean_sum + pow((student[j].GetAvg() - mean), 2);
  }

  stdev = sqrt(sqmean_sum/(j-1));

  for(int k = 0; k < i; ++k) {
    student[k].PrintGrade(mean, stdev);
  }
}

void studentype::InputData(int input_id, int input_grade[]) {
  sum = 0;
  id = input_id;
  for(int i = 0; i < 3; i++){
    grade[i] = input_grade[i];
    sum = sum + grade[i];
  }
  
  avg = sum / 3;

  return;
}

int studentype::GetAvg(void) {
  return avg;
}

void studentype::PrintGrade(double mean, double stdev) {
  const double BGrade = mean + 1.5*stdev;
  const double CGrade = mean + .5*stdev;
  const double DGrade = mean - .5*stdev;
  const double FGrade = mean - 1.5*stdev;
  
  if(avg >= BGrade)
    cout << id << " A" << endl;
  else if (avg >= CGrade)
    cout << id << " B" << endl;
  else if (avg >= DGrade)
    cout << id << " C" << endl;
  else if (avg >= FGrade)
    cout << id << " D" << endl;
  else if (avg < FGrade)
    cout << id << " F" << endl;
}
  
