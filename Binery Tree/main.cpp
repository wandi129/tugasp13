#include <iostream>

#include "BT.h"

using namespace std;
int main()
{
    PohonBiner pohon;
    string dataNama;
    cout<< " masukan nama:    ";
    cin>> dataNama;
    for (unsigned int i =0; i < dataNama.length();i++)
    {
        if (pohon.sisip(dataNama[i]) == false)
           cout<< "Data "<< dataNama[i] << " sudah ada" <<endl;
        else
            cout << "Data " << dataNama[i] << "disimpan" << endl;
    }
     cout << "in0der: " << pohon.in0rder() <<endl;
     cout << "pre0rder: " <<pohon.pre0rder() <<endl;
     cout << "post0rder: " <<pohon.post0rder() <<endl;

     pohon.hapus('A');
     pohon.hapus('i');
     pohon.hapus('E');

     cout << "Setelah A,i dan E dihapus: " <<endl
          << "pre0rder; "
          << pohon.pre0rder() << endl;
    return 0;
}
