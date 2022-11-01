//
// Originally Created by Jake Barnby
//

#ifndef CPP_RUNTIME_WRAPPER_H
#define CPP_RUNTIME_WRAPPER_H

#include "RuntimeResponse.h"
#include "RuntimeRequest.h"

namespace runtime
{
    class Wrapper
    {
    public:
        static RuntimeResponse &main(const RuntimeRequest &req, RuntimeResponse &resp)
        {
            std::string payload = req.payload;
            Json::Value variables = req.variables;
            Json::Value headers = req.headers;
            Json::Value json;
            json["payload"] = payload;
            json["variables"] = variables;
            json["headers"] = headers;
            return resp.json(json);
        }
    };
}

#endif //CPP_RUNTIME_WRAPPER_H
