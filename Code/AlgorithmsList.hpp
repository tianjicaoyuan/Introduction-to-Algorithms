#include "Algorithms.h"
#include <map>
#include <list>

#include "InsertionSort.h"
#include "MergeSort.h"

class AlgorithmsList
{
public:
    AlgorithmsList()
    {
        Algorithms* alg = NULL;

        alg = new InsertionSort();
        m_list.push_back(alg->GetInfo());
        m_map.insert(pair<string, Algorithms*>(alg->GetInfo().id, alg));
        
        alg = new MergeSort();
        m_list.push_back(alg->GetInfo());
        m_map.insert(pair<string, Algorithms*>(alg->GetInfo().id, alg));
    }

    ~AlgorithmsList()
    {
        m_list.clear();

        for(map<string, Algorithms*>::iterator itor = m_map.begin();
            itor!=m_map.end(); itor++)
        {
            delete itor->second;
            itor->second =NULL;
        }
        m_map.clear();
    }

    list<AlgorithmsInfo>* GetList()
    {
        return &m_list;
    }

    bool RunAlgorithmsByID(string id)
    {
        Algorithms* p = NULL;
        try
        {
            p = m_map.at(id);
        }
        catch (...)
        {
            p = NULL;
        }

        if (p == NULL)
        {
            perror("Can't find Algorithms\n");
            return false;
        }
        else
        {
            printf("[%s]%s run:\n", p->GetInfo().id.c_str(), p->GetInfo().name.c_str());
            p->Run();
            return true;
        }
    }

private:
    list<AlgorithmsInfo> m_list;
    map<string, Algorithms*> m_map;
};