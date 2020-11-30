#include "PCH.h"
#include "model.hpp"
//#include "Token.hpp"

class DBMS
{
private:
    vector<PersonModel> DATABASAE;
    vector<PersonModel> tmp_DATABASAE;
    string rootFileDir;
    string nameDB;
public:
    DBMS();
    ~DBMS();

    /*
    Initialyze work with database. Read date in buf DATABASE
    */
    void init();

    /*
        Desct:
            This method specifyed path and name of DB sorce file.
        Param:
            const string& src - absolute path to file
    */
    void setSorce(const string& src);

    /*
        Method that add new record in temporary buf tmp_DATABASAE
     */
    void insert(PersonModel record);

    /*
        write new records from tmp_DATABASE in file and update DATABASE
    */
    void commit();

    /*
        Sort a DATABASE into selected order by field
        ASC - true 
        DESC - false 
    */
    void sortBy(string field, bool order = true);

    /*
        This function find rows matching a condition and copy them in tmp_DATABASAE.
        all data in tmp_DATABASAE situated before runing this function will be deleted
    */
    void DBMS::selectWhere(std::function<bool(PersonModel i)> const & alg);

    /*
        return result of operation
    */
    vector<PersonModel> getResult();
};