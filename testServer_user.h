#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

namespace testServer
{
class user : public drogon::HttpController<user>
{
  public:
      METHOD_LIST_BEGIN
      // use METHOD_ADD to add your custom processing function here;
      METHOD_ADD(user::login, "/token?userId={1}&passwd={2}", Post);
      METHOD_ADD(user::getInfo, "/{1}/info?token={2}", Get);
      METHOD_ADD(user::newUser, "/users", Post);
    // METHOD_ADD(user::get, "/{2}/{1}", Get); // path is /testServer/user/{arg2}/{arg1}
    // METHOD_ADD(user::your_method_name, "/{1}/{2}/list", Get); // path is /testServer/user/{arg1}/{arg2}/list
    // ADD_METHOD_TO(user::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list

      METHOD_LIST_END
          // your declaration of processing function maybe like this:
          void login(const HttpRequestPtr& req,
              std::function<void(const HttpResponsePtr&)>&& callback,
              std::string&& userId,
              const std::string& pssword);
      void getInfo(const HttpRequestPtr& req,
          std::function<void(const HttpResponsePtr&)>&& callback,
          std::string userId,
          const std::string& token) const;
      void newUser(const HttpRequest& req,
          std::function<void(const HttpResponsePtr&)> &&callback) const;
    // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
    // void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;
};
}
