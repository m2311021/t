#include <drogon/drogon.h>

namespace myapp {
    struct User {
        std::string userName;
        std::string email;
        std::string address;
    };

    inline User fromRequest_(const drogon::HttpRequest& req) //
    {
        auto json = req.getJsonObject();
        myapp::User user;
        if (json)
        {
            user.userName = (*json)["name"].asString();
            user.email = (*json)["email"].asString();
            user.address = (*json)["address"].asString();
        }
        return user;
    }
}
