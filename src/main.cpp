#include <drogon/drogon.h>
using namespace drogon;
#ifdef NDEBUG
  #define COSIM_CONFIG_FILE COSIM_CONFIG_FILE_RELEASE
#else
  #define COSIM_CONFIG_FILE COSIM_CONFIG_FILE_DEBUG
#endif
int main(int argc, char* argv[]) {
  drogon::app().loadConfigFile("D:\\repo_dir\\cosim\\config\\config.json");
  // 全局后置处理：CORS 示例
  drogon::app().registerPostHandlingAdvice([](auto& req, auto& resp){
    if (req->getMethod()!=drogon::Options) {
      resp->addHeader("Access-Control-Allow-Origin", "*");
      resp->addHeader("Access-Control-Allow-Methods", "GET,POST,PUT,DELETE,OPTIONS");
      resp->addHeader("Access-Control-Allow-Headers", "Content-Type,Authorization");
    }
  });
  drogon::app().registerHandler("/test?username={name}",
                    [](const HttpRequestPtr& req,
                       std::function<void (const HttpResponsePtr &)> &&callback,
                       const std::string &name)
                    {
                        Json::Value json;
                        json["result"]="ok";
                        json["message"]=std::string("hello,")+name;
                        auto resp=HttpResponse::newHttpJsonResponse(json);
                        callback(resp);
                    },
                    {Get,"LoginFilter"});

  drogon::app().run();
  return 0;
}
