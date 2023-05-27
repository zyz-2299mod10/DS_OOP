
class quick{
public:
    quick(vector<int> v_) : v(v_){};

    vector<int> sort(){
        quick_sort_partation(0, v.size() -1 );
        return v;
    }

    vector<int> sort_print(){
        quick_sort_partation_print(0, v.size()-1);
        return v;
    }

    void quick_sort_partation_print(int front, int rear){
        if (front < rear)
        {
            int pivot = v[front];
            int f = front;
            int r = rear + 1;

            while (true)
            {
                while (f < rear && v[++f] < pivot);
                while (r > 0 && v[--r] > pivot);

                if (f >= r) break;

                swap(v[f], v[r]);
            }

            swap(v[front], v[r]);
            cout << front << "-" << rear << setw(2) << " : \n";
            print_v();

            quick_sort_partation_print(front, r - 1);
            quick_sort_partation_print(r + 1, rear);
        }
    }

    void quick_sort_partation(int front, int rear){
        if (front < rear)
        {
            int pivot = v[front];
            int f = front;
            int r = rear + 1;

            while (true)
            {
                while (f < rear && v[++f] < pivot);
                while (r > 0 && v[--r] > pivot);

                if (f >= r) break;

                swap(v[f], v[r]);
            }

            swap(v[front], v[r]);

            quick_sort_partation(front, r - 1);
            quick_sort_partation(r + 1, rear);
        }
    }

    void print_v(){
        for(auto vi : v){
            cout << vi << ",";
        }
        cout << endl;
    }

    void swap(int& a, int& b)
    {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }

public:
    vector<int> v;
};