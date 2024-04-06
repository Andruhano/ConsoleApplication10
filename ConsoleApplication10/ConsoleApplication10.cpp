#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*class IOutput
{
public:
    virtual void Show() = 0;
    virtual void Show(const string& info) = 0;
};

class Array : public IOutput 
{
vector<int> array;
public:
    Array(const vector<int>& arr) : array(arr) {}

    void Show() 
    {
        cout << "�������� �������:" << endl;
        for (int num : array) 
        {
            cout << num << " ";
        }
        cout << endl;
    }

    void Show(const string& info) 
    {
        cout << info << endl;
        Show();
    }
};

int main() 
{
    system("chcp 1251");
    vector<int> numbers = { 1, 2, 3, 4, 5 };
    Array arr(numbers);

    arr.Show(); 
    arr.Show("�������������� ���������"); 

    return 0;
}*/

/*
class IMath 
{
public:
    virtual int Max() const = 0;
    virtual int Min() const = 0;
    virtual float Avg() const = 0;
    virtual bool Search(int valueToSearch) const = 0;
};

class Array : public IMath 
{
vector<int> array;

public:
    Array(const vector<int>& arr) : array(arr) {}

    int Max() const 
    {
        return *max_element(array.begin(), array.end());
    }
    int Min() const
    {
        return *min_element(array.begin(), array.end());
    }

    float Avg() const override 
    {
        if (array.empty())
            return 0;

        int sum = 0;
        for (int num : array) 
        {
            sum += num;
        }
        return static_cast<float>(sum) / array.size();
    }

    bool Search(int valueToSearch) const 
    {
        return find(array.begin(), array.end(), valueToSearch) != array.end();
    }
};

int main() 
{

    system("chcp 1251");
    vector<int> numbers = { 1, 2, 3, 4, 5 };
    Array arr(numbers);

    cout << "��������: " << arr.Max() << endl;
    cout << "�������: " << arr.Min() << endl;
    cout << "�������: " << arr.Avg() << endl;
    cout << "����� 3: " << (arr.Search(3) ? "�������" : "�� �������") << endl;
    cout << "����� 6: " << (arr.Search(6) ? "�������" : "�� �������") << endl;

    return 0;
}
*/

class ISort 
{
public:
    virtual void SortAsc() = 0;
    virtual void SortDesc() = 0;
    virtual void SortByParam(bool isAsc) = 0;
};

class Array : public ISort 
{
vector<int> array;

public:
    Array(const vector<int>& arr) : array(arr) {}

    void SortAsc() 
    {
        sort(array.begin(), array.end());
    }

    void SortDesc() 
    {
        sort(array.begin(), array.end(), greater<int>());
    }

    void SortByParam(bool isAsc) 
    {
        if (isAsc)
            SortAsc();
        else
            SortDesc();
    }

    void Show() 
    {
        cout << "�������� �������:";
        for (int num : array) 
        {
            cout << " " << num;
        }
        cout << endl;
    }
};

int main() 
{
    system("chcp 1251");

    vector<int> numbers = { 5, 3, 8, 1, 6 };
    Array arr(numbers);

    cout << "���������� �� �����������:" << endl;
    arr.SortByParam(true);
    arr.Show();

    cout << "���������� �� ��������:" << endl;
    arr.SortByParam(false);
    arr.Show();

    return 0;
}
