/**
* @licence app begin@
* SPDX-License-Identifier: MPL-2.0
*
* \copyright Copyright (C) 2013-2015, PCA Peugeot Citroen
*
* \file poi-manager-server-stub.h
*
* \brief This file is part of the poi proof of concept.
*
* \author Philippe Colliot <philippe.colliot@mpsa.com>
*
* \version 0.1
*
* This Source Code Form is subject to the terms of the
* Mozilla Public License (MPL), v. 2.0.
* If a copy of the MPL was not distributed with this file,
* You can obtain one at http://mozilla.org/MPL/2.0/.
*
* For further information see http://www.genivi.org/.
*
* List of changes:
* <date>, <name>, <description of change>
*
* @licence end@
*/
#ifndef POIMANAGERSERVERSTUBIMPL_H_
#define POIMANAGERSERVERSTUBIMPL_H_

#include <CommonAPI/CommonAPI.h>

#include "org/genivi/navigation/poiservice/POIContentManagerStubDefault.h"

#include "poi-common-database.h"

#include "poi-common-data-model.h"

using namespace std;
using namespace org;
using namespace genivi;
using namespace navigation;
using namespace poiservice;

class sqlRequest
{
public:

    typedef enum
    {
        CATEGORY_NOT_EXIST,
        CATEGORY_NAME_ALREADY_EXIST,
        CATEGORY_ID_NOT_EXIST,
        ATTRIBUTE_ID_NOT_EXIST,
        PARENT_CATEGORY_NOT_EXIST,
        DATABASE_ACCESS_ERROR,
        OK
    } SQL_REQUEST_ERRORS;

    sqlRequest();
    ~sqlRequest();
    SQL_REQUEST_ERRORS setDatabase(const char* poiDatabaseFileName);
    vector<poi_category_common_t> getAvailableCategories(POIServiceTypes::CategoryID& rootCategory);
    SQL_REQUEST_ERRORS createCategory(POIServiceTypes::CAMCategory category,POIServiceTypes::CategoryID& unique_id);
    SQL_REQUEST_ERRORS removeCategory(POIServiceTypes::CategoryID unique_id);

private:
    const char* m_SQL_REQUEST_GET_AVAILABLE_CATEGORIES = "SELECT Id,name FROM poicategory WHERE Id IN (SELECT poicategory_Id FROM belongsto GROUP BY poicategory_Id);";
    const char* m_SQL_REQUEST_GET_CATEGORY_ATTRIBUTES = "SELECT Id,name FROM poiattribute WHERE Id IN (SELECT poiattribute_Id FROM hasattribute WHERE poicategory_Id IS ";
    const char* m_SQL_REQUEST_GET_AVAILABLE_AREA = "SELECT leftlongitude,bottomlatitude,rightlongitude,toplatitude FROM availablearea;";
    const char* m_SQL_REQUEST_GET_PARENT_CATEGORIES = "SELECT parentId FROM poicategorykinship WHERE childId IS ";
    const char* m_SQL_REQUEST_GET_CHILD_CATEGORIES = "SELECT childId FROM poicategorykinship WHERE parentId IS ";
    const char* m_SQL_REQUEST_GET_CATEGORY_ICONS = "SELECT url,format FROM iconset WHERE Id IS (SELECT iconset_Id FROM isdisplayedas WHERE poicategory_Id IS  ";
    const char* m_SQL_REQUEST_GET_AVAILABLE_NEXT_FREE_CATEGORY_ID = "SELECT a.id+1 FROM poicategory a WHERE NOT EXISTS (SELECT * FROM poicategory b WHERE a.id+1 = b.id) ORDER BY a.id";
    const char* m_SQL_REQUEST_GET_AVAILABLE_NEXT_FREE_ATTRIBUTE_ID = "SELECT a.id+1 FROM poiattribute a WHERE NOT EXISTS (SELECT * FROM poicategory b WHERE a.id+1 = b.id) ORDER BY a.id";
    const char* m_SQL_REQUEST_GET_AVAILABLE_NEXT_FREE_POI_ID = "SELECT a.id+1 FROM poi a WHERE NOT EXISTS (SELECT * FROM poi b WHERE a.id+1 = b.id) ORDER BY a.id";
    const char* m_SQL_REQUEST_INSERT_CATEGORY = "INSERT INTO poicategory VALUES (";
    const char* m_SQL_REQUEST_DELETE_CATEGORY = "DELETE from poicategory WHERE id = ";
    const char* m_SQL_REQUEST_CHECK_IF_CATEGORY_ID_EXIST = "SELECT CASE WHEN EXISTS (SELECT * FROM poicategory WHERE id = ";
    const char* m_SQL_REQUEST_CHECK_IF_CATEGORY_NAME_EXIST = "SELECT CASE WHEN EXISTS (SELECT * FROM poicategory WHERE name = ";
    const char* m_SQL_REQUEST_INSERT_ATTRIBUTE = "INSERT INTO poiattribute VALUES (";
    const char* m_SQL_REQUEST_DELETE_ATTRIBUTE = "DELETE from poiattribute WHERE id = ";
    const char* m_SQL_REQUEST_CHECK_IF_ATTRIBUTE_ID_EXIST = "SELECT CASE WHEN EXISTS (SELECT * FROM poiattribute WHERE id = ";
    const char* m_SQL_REQUEST_GET_POI_PROVIDER_ID = "(SELECT Id FROM poiprovider WHERE name='OpenStreetMap')";
    const char* m_SQL_RETURN_BOOL_VALUE = " THEN CAST(1 AS BIT) ELSE CAST(0 AS BIT) END;";
    const char* m_SQL_REQUEST_INSERT_BELONGSTO = "INSERT INTO belongsto (Id,poiprovider_Id,poicategory_Id,poi_Id) ";

    Database *mp_database; // database access

    // string conversion to numeric: the third parameter of fromString() should be one of std::hex, std::dec or std::oct
    template <class T>
    bool fromString(T& t, const std::string& s, std::ios_base& (*f)(std::ios_base&))
    {
      std::istringstream iss(s);
      return !(iss >> f >> t).fail();
    }

    void onError();

    SQL_REQUEST_ERRORS checkIfCategoryNameDoesntExist(std::string name);

    SQL_REQUEST_ERRORS checkIfCategoryIdExist(POIServiceTypes::CategoryID unique_id);

    SQL_REQUEST_ERRORS checkIfAttributeExist(POIServiceTypes::AttributeID unique_id);

    SQL_REQUEST_ERRORS getFreeCategoryId(POIServiceTypes::CategoryID &unique_id);

    SQL_REQUEST_ERRORS getFreeAttributeId(POIServiceTypes::AttributeID &unique_id);

    void getAvailableArea();

    NavigationTypes::Coordinate2D m_leftBottomLocation,m_rightTopLocation;

};


class PoiManagerServerStub: public org::genivi::navigation::poiservice::POIContentManagerStubDefault {

public:
    PoiManagerServerStub();
    ~PoiManagerServerStub();
    void getVersion(const std::shared_ptr<CommonAPI::ClientId> clientId, NavigationTypes::Version& version);
    void setLocale(const std::shared_ptr<CommonAPI::ClientId> clientId, std::string languageCode, std::string countryCode, std::string scriptCode);
    void getLocale(const std::shared_ptr<CommonAPI::ClientId> clientId, std::string& languageCode, std::string& countryCode, std::string& scriptCode);
    void getSupportedLocales(const std::shared_ptr<CommonAPI::ClientId> clientId, std::vector<POIServiceTypes::Locales>& localeList);
    void getAvailableCategories(const std::shared_ptr<CommonAPI::ClientId> clientId, std::vector<POIServiceTypes::CategoryAndName>& categories);
    void getRootCategory(const std::shared_ptr<CommonAPI::ClientId> clientId, POIServiceTypes::CategoryID& category);
    void getChildrenCategories(const std::shared_ptr<CommonAPI::ClientId> clientId, POIServiceTypes::CategoryID category, std::vector<POIServiceTypes::CategoryAndLevel>& categories);
    void getParentCategories(const std::shared_ptr<CommonAPI::ClientId> clientId, POIServiceTypes::CategoryID category, std::vector<POIServiceTypes::CategoryAndLevel>& categories);
    void createCategory(const std::shared_ptr<CommonAPI::ClientId> clientId, POIServiceTypes::CAMCategory category, POIServiceTypes::CategoryID& unique_id);
    void removeCategories(const std::shared_ptr<CommonAPI::ClientId> clientId, std::vector<POIServiceTypes::CategoryID> categories);
    void addPOIs(const std::shared_ptr<CommonAPI::ClientId> clientId, POIServiceTypes::CategoryID unique_id, std::vector<POIServiceTypes::PoiAddedDetails> poiList);
    void removePOIs(const std::shared_ptr<CommonAPI::ClientId> clientId, std::vector<POIServiceTypes::POI_ID> ids);
    bool initDatabase(const char* poiDatabaseFileName);

private:
    NavigationTypes::Version m_version;
    std::string m_languageCode, m_countryCode, m_scriptCode;

    uint16_t m_availableCategories;
    vector<poi_category_common_t> m_availableCategoryTable;
    POIServiceTypes::CategoryID m_rootCategory;
    NavigationTypes::Coordinate3D m_centerLocation;

    sqlRequest* mp_sqlRequest;
    void refreshCategoryList();

    // string conversion to numeric: the third parameter of fromString() should be one of std::hex, std::dec or std::oct
    template <class T>
    bool fromString(T& t, const std::string& s, std::ios_base& (*f)(std::ios_base&))
    {
      std::istringstream iss(s);
      return !(iss >> f >> t).fail();
    }

};

#endif /* POIMANAGERSERVERSTUBIMPL_H_ */