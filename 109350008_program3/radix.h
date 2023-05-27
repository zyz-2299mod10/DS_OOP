#include <math.h>
#include <list>

class radix{
public:
    radix(vector<int> v_) : v(v_) {};

    vector<int> sort(){
        int m, p;
        list<int> pocket[10];
        for (int i = 0; i < 3; i++) {
            m = pow(10, i + 1);
            p = pow(10, i);
            for (int j = 0; j < v.size() ; j++) {
                int temp = v[j] % m;
                int index_pocket = temp / p;
                pocket[index_pocket].push_back(v[j]);
            }
            int index_v = 0;
            for (int j = 0; j < 10; j++) {
                while (!pocket[j].empty()) {
                    v[index_v] = *(pocket[j].begin());
                    pocket[j].erase(pocket[j].begin());
                    index_v++;
                }
            }
        }

        return v;
    }

    vector<int> sort_print(){

        int m, p;
        list<int> pocket[10];
        for (int i = 0; i < 3; i++) {

            cout << "\nThe " << i + 1 << " pass : " << endl;
            m = pow(10, i + 1);
            p = pow(10, i);
            for (int j = 0; j < v.size(); j++) {
                int temp = v[j] % m;
                int index_pocket = temp / p;
                pocket[index_pocket].push_back(v[j]);
            }
            int index_v = 0;
            for (int j = 0; j < 10; j++) {
                
                cout << j << " | ";
                while (!pocket[j].empty()) {
                    v[index_v] = *(pocket[j].begin());
                    cout << "--> " << *(pocket[j].begin()) << " " ;
                    pocket[j].erase(pocket[j].begin());
                    index_v++;
                }
                cout << endl;
            }

            cout << "resulting chain : ";
            print_v();
        }

        return v;
    }
    
    void print_v(){
        for(auto vi : v){
            cout << vi << ",";
        }
        cout << endl;
    }

public:
    vector<int> v;
};