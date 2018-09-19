class Test
{
    private:
        int data1;
        float data2;

    public:

       void insertIntegerData(int d)
       {
          data1 = d;
          cout << "Number: " << data1;
        }

       float insertFloatData()
       {
           cout << "\nEnter data: ";
           cin >> data2;
           return data2;
        }
};

