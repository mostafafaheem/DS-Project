
#include <string>
#include <iostream>
#include <map>

#include<vector>
#include "search.h"
#include <crow.h>
#include "auth.h"
#include "database.h"
#include "crow/middlewares/cors.h"

using namespace std;






int main()
{
	
	//database* db = new database();
	//search* se = new search();
	//db->addListing(122.0f, "aaa", "aaaa", "aaaa", "aaaa");
	//db->addListing(122.0f, "aaab", "aaaa", "aaaa", "aaaa");
	//db->addListing(122.0f, "aaac", "aaaa", "aaaa", "aaaa");
	//db->addListing(122.0f, "aaas", "aaaa", "aaaa", "aaaa");
	//vector<string> s = se->searchByName("a");
	//for (string i : s) cout << i << endl;

    crow::App<crow::CORSHandler> app;

    // Customize CORS
    
   
    

    CROW_ROUTE(app, "/auth/register")
        .methods("POST"_method)
        ([](const crow::request& req) {
        if (!req.body.empty()) {
            crow::json::rvalue json = crow::json::load(req.body);

            if (!json) {
                return crow::response(400);
            }
            crow::response response;
            response.set_header("Content-Type", "application/json"); 
            response.set_header("Access-Control-Allow-Origin", "*"); 
           


            string name = json["username"].s();
            string password = json["password"].s();
            string email = json["Email"].s();
            string phone = json["Phone"].s();
            Auth* auth = new Auth();
            string res = auth->registerUser(name, email, password, phone);
            response.body = "{message:" + res + "}";

            return response;
        }
        else {
            return crow::response(400);
        }
            });
    
    CROW_ROUTE(app, "/auth/login")
        .methods("POST"_method)
        ([](const crow::request& req, crow::response& response) {
        string key = "Access-Control-Allow-Origin";
        string value = "*";
        response.add_header(key, value);
        if (!req.body.empty()) {
            crow::json::rvalue json = crow::json::load(req.body);
            if (!json) {
                response.code = 400;
                response.end() ;
            }




            string email = json["Email"].s();
            string password = json["password"].s();

            Auth* auth = new Auth();
            bool res = auth->loginUser(email, password);
            if (!res) {
                response.code = 400;
                response.end();
            }
            
            
            response.write("{email:"+email+"}");
            response.end();
        }
        else {
           
            response.code = 400;
            response.end();
        }
            });

    app.port(3000).multithreaded().run();
    return 0;

}




