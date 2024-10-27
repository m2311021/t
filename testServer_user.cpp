#include "testServer_user.h"
#include "UserController.h"
#include <drogon/drogon.h>

using namespace testServer;
using namespace drogon;

void user::login(const HttpRequestPtr& req,
	std::function<void(const HttpResponsePtr&)>&& callback,
	std::string&& userId,
	const std::string& password)
{
	LOG_DEBUG << "user" << userId << " login";
	//authenication algorithm, read database, verify, identify, etc...
	//...
	Json::Value ret;
	ret["result"] = "ok";
	ret["ttoken"] = drogon::utils::getUuid();
	auto resp = HttpResponse::newHttpJsonResponse(ret);
	callback(resp);
}

void user::getInfo(const HttpRequestPtr& req,
	std::function<void(const HttpResponsePtr&)>&& callback,
	std::string userId,
	const std::string& token) const
{
	LOG_DEBUG << "user" << userId << " get his information";
	//verify the validity of the token, etc.
	//Read the database or cache to get user information
	Json::Value ret;
	ret["result"] = "ok";
	ret["user_name"] = "Jack";
	ret["user_id"] = userId;
	ret["gender"] = 1;
	auto resp = HttpResponse::newHttpJsonResponse(ret);
	callback(resp);
}

void user::newUser(const HttpRequest& req,
	std::function<void(const HttpResponsePtr&)>&& callback) const
{
	myapp::User newUser = myapp::fromRequest_(req);

	Json::Value ret;
	ret["result"] = "ok";

	auto resp = HttpResponse::newHttpJsonResponse(ret);
	callback(resp);
}