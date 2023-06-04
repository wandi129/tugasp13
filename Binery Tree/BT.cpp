#include <iostream>
#include <string.h>
#include "BT.h"

using namespace std;

NodePohon::NodePohon(char data)
{
    NodePohon::data = data;
    NodePohon::induk = NULL;
    NodePohon::kiri = NULL;
    NodePohon::kanan = NULL;
}

PohonBiner::PohonBiner()
{
    PohonBiner::akar = NULL;

}
PohonBiner::~PohonBiner()
{
    hapusSemuaNode(akar);
}
bool PohonBiner::sisip(NodePohon* &ortu, NodePohon* ptrBaru)
{
    if (ptrBaru->data == ortu->data)
    {
        delete ptrBaru;
        return false;
    }
    else
        if (ptrBaru->data < ortu -> data)
            if (ortu->kiri == NULL)
    {
             ortu->kiri =ptrBaru;
             ptrBaru->induk = ortu;
             return true;
    }
    else
        return sisip(ortu->kiri, ptrBaru);
    else
        if (ortu->kanan == NULL)
    {
        ortu->kanan =ptrBaru;
        ptrBaru->induk = ortu;
        return true;
    }
    else
        return sisip(ortu->kanan, ptrBaru);
}
bool PohonBiner::sisip(char data)
{
    NodePohon* ptrBaru = new NodePohon(data);
    if (akar == NULL)
    {
        akar = ptrBaru;
        return true;
    }
    else
        return sisip(akar, ptrBaru);
}
NodePohon* PohonBiner::cari(NodePohon* &akar, char data)
{
    if (akar == NULL)
        return NULL;
    else
        if (data == akar->data)
        return akar;
    else
        if (data < akar ->data)
        return cari(akar->kiri, data);
    else
        return cari(akar->kanan, data);
}
bool PohonBiner::cari(char data)
{
    if (cari(akar, data) == NULL)
        return false;

    else
        return true;
}
bool PohonBiner::hapus(char data)
{
    NodePohon* nodeDihapus = cari(akar, data);
    if (nodeDihapus == NULL)
    {
        return true;
    }

    if (nodeDihapus->kanan == NULL )
        if (nodeDihapus->kiri == NULL)
    {
        if (nodeDihapus == akar)
            akar = NULL;
        else
            if (nodeDihapus->induk->kiri == nodeDihapus)
                nodeDihapus->induk->kiri = NULL;
        else
            nodeDihapus->induk->kanan = NULL;
    }
    else
    {
        if(nodeDihapus == akar)
        {
            akar = nodeDihapus->kiri;
            akar->induk = NULL;
        }
        else
        {
            if (nodeDihapus->induk->kiri == nodeDihapus)
            {
                nodeDihapus->induk->kiri = nodeDihapus->kiri;
                nodeDihapus->kiri->induk = nodeDihapus->induk;
            }
            else
            {
                nodeDihapus->induk->kanan = nodeDihapus->kiri;
                nodeDihapus->kiri->induk = nodeDihapus->induk;
            }
        }
    }
    else
        if (nodeDihapus->kiri == NULL)
    {
        if (nodeDihapus == akar)
        {
            akar = nodeDihapus->kanan;
            akar->induk = NULL;
        }
        else
            if (nodeDihapus->induk->kiri == nodeDihapus)
        {
            nodeDihapus->induk->kiri = nodeDihapus->kanan;
            nodeDihapus->kanan->induk = nodeDihapus->induk;
        }
        else
        {
            nodeDihapus->induk->kanan = nodeDihapus->kanan;
            nodeDihapus->kanan->induk = nodeDihapus->induk;
        }
    }
    else
    {
        NodePohon* suksesor = nodeDihapus->kanan;
        while (suksesor->kiri != NULL)
            suksesor = suksesor->kiri;

        if (suksesor->induk->kiri == suksesor)
        {
            suksesor->induk->kiri = suksesor->kanan;
            if (suksesor->kanan != NULL)
                suksesor->kanan->induk = suksesor->induk;
        }
        else
        {
            suksesor->induk->kanan = suksesor->kanan;
            if (suksesor->kanan != NULL)
                suksesor->kanan->induk = suksesor->induk;
        }
        nodeDihapus->data = suksesor->data;
        nodeDihapus = suksesor;
    }
    delete nodeDihapus;
    return true;
}
    string PohonBiner::in0rder(NodePohon* ptrNode)
    {
        string hasil = "";
        if (ptrNode != NULL)
        {
            if (ptrNode->kiri != NULL)
                hasil = hasil + in0rder(ptrNode->kiri);

            hasil = hasil + ptrNode->data;

            if (ptrNode->kanan != NULL)
                hasil = hasil + in0rder (ptrNode->kanan);
        }
        return hasil;
    }
    string PohonBiner::in0rder()
    {
        return in0rder(akar);
    }
       string PohonBiner::pre0rder(NodePohon* ptrNode)
    {
        string hasil = "";
        if (ptrNode != NULL)
        {
                hasil = hasil + ptrNode->data;
            if (ptrNode->kiri != NULL)
            hasil = hasil + pre0rder (ptrNode->kiri);

            if (ptrNode->kanan != NULL)
                hasil = hasil + pre0rder (ptrNode->kanan);
        }
        return hasil;
    }
    string PohonBiner::pre0rder()
    {
        return pre0rder(akar);
    }
    string PohonBiner::post0rder(NodePohon* ptrNode)
    {
        string hasil = "";
        if (ptrNode != NULL)
        {
            if (ptrNode->kiri != NULL)
            hasil = hasil + post0rder (ptrNode->kiri);

            if (ptrNode->kanan != NULL)
                hasil = hasil + post0rder (ptrNode->kanan);

                hasil = hasil + ptrNode->data;
        }
        return hasil;
    }

    string PohonBiner::post0rder()
    {
        return post0rder(akar);
    }
    void PohonBiner::hapusSemuaNode(NodePohon* ptrNode)
    {
        if (ptrNode != NULL)
        {
            hapusSemuaNode(ptrNode->kiri);
            hapusSemuaNode(ptrNode->kanan);

          delete ptrNode;
    }
}
