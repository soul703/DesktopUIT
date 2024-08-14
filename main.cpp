#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include<vector>
using namespace std;

void taoMang2Chieu(int a[][100], int n) {
  // Khởi tạo bộ tạo số ngẫu nhiên
  srand(time(NULL));

  // Duyệt qua từng phần tử trong mảng
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // Tạo số ngẫu nhiên trong phạm vi [-39, 79]
      a[i][j] = rand() % 120 - 39;
    }
  }
}
//hàm tìm giá trị lớn nhât
int timMax(int a[][100], int n) {
  // Khởi tạo giá trị lớn nhất ban đầu
  int maxValue = a[0][0];

  // Duyệt qua từng phần tử trong mảng
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] > maxValue) {
        maxValue = a[i][j];
      }
    }
  }

  return maxValue;
}
// Tạo hàm kiemr tra số nguyên tố
bool ktsonguyento(int a)
{
   if(a<2)
    return false ;
   else
    for(int i = 2 ; i < sqrt(a);i++ )
   {
      if( a%i == 0)
        return false ;


   }
   return true ;
}
int songuyento(int a[][100], int n)
{
     cout<<"so nguyen to :"<<endl;
    for (int i = 0 ; i < n ; i++)
    {

        for (int j = 0 ; j < n ; j++)
    {
        if(ktsonguyento(a[i][j]))

           cout<<a[i][j]<<'\t';
    }
    }
    cout<<endl;
}
// In các phần tử ở đường chéo chính
void Duongcheochinh(int a [][100],int n)
{
    cout<<"cac phan tu duong cheo chinh :"<<endl;
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n; j++)
        {
            if(i == j)
                cout<< a[i][j]<<"\t";
        }
    }
    cout<<endl;
}
void Duongcheophu(int a [][100],int n)
{
    cout<<"cac phan tu duong cheo phu :"<<endl;
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n; j++)
        {
            if(i + j ==n -1)
                cout<< a[i][j]<<"\t";
        }
    }
    cout<<endl;
}
// Tổng giá trị nằm dưới đường chéo phụ

int Tongphu(int a[][100],int n)
{
    int tong = 0 ;vector<int>v;
    for(int i = 0 ; i < n ;i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(i > j)
            {
                tong += a[i][j];
                v.push_back(a[i][j]);
            }
        }
    }
    return v;
}
// tìm giá trị nhỏ nhất trên tùng dòng của mảng
int Mindong(int a[][100],int n,int sodong)
{
    int mindong = a[sodong-1][0];
    for(int  i = 1 ; i < n ; i++)
    {
        if(mindong > a[sodong-1][i])
            mindong = a[sodong-1][i];
    }
    return mindong ;
}
// tìm giá trị nhỏ nhất trên tùng cột của mảng
int Mincot(int a[][100],int n,int socot)
{
    int mincot = a[0][socot-1];
    for(int  i = 1 ; i < n ; i++)
    {
        if(mincot > a[i][socot-1])
            mincot = a[i][socot-1];
    }
    return mincot ;
}
// Kiểm tra mảng toàn giá trị chẵn
bool kiemtrachan(int a[][100],int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        for ( int j = 0 ; j< n ; j++)
        {
            if(a[i][j]< 0)
                return false ;
        }
    }
    return true ;
}
// tìm giá trị lớn nhất trong mảng
int maxchan(int a[][100], int n)
{
    int maxchan = a[0][0];
  for(int i = 0 ; i < n ; i++)
    {
        for ( int j = 0 ; j< n ; j++)
        {
            if(a[i][j]%2 != 0)
            continue;
            if(maxchan < a[i][j])
            maxchan = a[i][j];
        }
    }
    return maxchan ;
}
// In tan suất các giá tri xuất hiện tỏng mảng:

{

}
int main() {
  int n; // Kích thước mảng (số hàng và số cột)

  // Nhập kích thước mảng
  cout << "Nhap kich thuoc mang 2 chieu vuong: ";
  cin >> n;

  // Khai báo mảng 2 chiều
  int a[100][100];

  // Gọi hàm tạo mảng ngẫu nhiên
  taoMang2Chieu(a, n);

  // Xuất mảng 2 chiều
  cout << "\nMang 2 chieu vua tao:\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout  <<a[i][j] << " ";
    }
    cout << endl;
  }
  songuyento(a,n);
    Duongcheochinh(a,n);
    Duongcheophu(a,n);
cout<<Tongphu(a,n)<<endl;
cout<< "Min cua dong 2 la :" <<Mindong(a,n,2)<<endl;
cout<< "Min cua cot 2 la :" <<Mincot(a,n,2)<<endl;
cout<< "GT chan lon nhat cua mang: "<<maxchan(a,n)<<endl;
  return 0;
}

