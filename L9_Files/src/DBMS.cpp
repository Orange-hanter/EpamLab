#include "DBMS.h"

uint16_t PersonModel::fildId = 0;

using PM = PersonModel;

DBMS::DBMS( ){
    rootFileDir = "C:/Users/Danil/Desktop/workArea/";
    nameDB = "DB";
}

DBMS::~DBMS()
{
}

void DBMS::init(){
    std::fstream ifs;
    ifs.open(rootFileDir + nameDB, std::ios::in);
    if( ifs.is_open()){
        string metaInfoLine;    //TODO use it later. Check vith shema
        std::getline(ifs, metaInfoLine);

        string line;
        while (std::getline(ifs, line))
        {
           DATABASAE.push_back(PersonModel::makeModel(line));
        }

        ifs.close();
    } 
    else if (ifs.fail()){
        std::cerr << "Cudn`t open file:" << rootFileDir + nameDB
                << "Initilyze new record."<<endl;
        ofstream ofs;
        ofs.open(rootFileDir + nameDB, std::ios::out);
        ofs << PersonModel::getMetaInformation() << endl;
        ofs.close();
    }
}

void DBMS::setSorce(const string& src){
    rootFileDir = src;
}

void DBMS::insert(PersonModel record){
    tmp_DATABASAE.push_back(record);
}

void DBMS::commit(){
    ofstream ofs;
    ofs.open(rootFileDir + nameDB, std::ios::out | std::ios::app);
    for (PersonModel& record : tmp_DATABASAE)
        ofs << record << '\n';
    DATABASAE.clear();
    ofs.close();
    this->init();
}

void DBMS::sortBy(string field, bool order){
    if (field != "")
    {
        /* code to check correct field*/
    }
    
    PersonModel::setAccentField(field);
    if (order)    
        sort( begin(tmp_DATABASAE), end(tmp_DATABASAE), PM::isLess );
    else
        sort( begin(tmp_DATABASAE), end(tmp_DATABASAE), PM::isGreat );
    
}

void DBMS::selectWhere(std::function<bool (PersonModel i)> const & alg){
    //copy_if(begin(DATABASAE), end(DATABASAE), tmp_DATABASAE.begin(), alg);
    for(auto& elem : DATABASAE){
        if (alg(elem))
        {
            tmp_DATABASAE.push_back(elem);
        }
        
    }
}

vector<PersonModel> DBMS::getResult(){
    return tmp_DATABASAE;
}