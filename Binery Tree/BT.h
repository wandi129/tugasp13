#ifndef BT_H_INCLUDED
#define BT_H_INCLUDED

#include <string>
using namespace std;

class NodePohon
{
     public:
            char data;
            NodePohon* induk;
            NodePohon* kiri;
            NodePohon* kanan;

            NodePohon(char karakter);
};

class PohonBiner
{
        private:
        NodePohon* akar;
        bool sisip(NodePohon* &ortu, NodePohon* ptrBaru);
        NodePohon* cari (NodePohon* &akar, char data);
        string in0rder (NodePohon* ptrNode);
        string pre0rder (NodePohon* ptrNode);
        string post0rder (NodePohon* ptrNode);
        void hapusSemuaNode (NodePohon* ptrNode);

    public:
        PohonBiner();
        ~PohonBiner();
        bool sisip(char data);
        bool cari(char data);
        bool hapus(char data);
        string in0rder();
        string pre0rder();
        string post0rder();

};


#endif // BT_H_INCLUDED
