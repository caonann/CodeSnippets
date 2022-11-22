//
// Created by cn on 2022/11/21.
//
#include <sstream>
#include <iostream>
#include <map>
#include <tuple>

using namespace  std;
std::tuple<std::map<std::string, std::string>, int> ParseUrl(const std::string& param) {
  std::istringstream iss(param);
  std::map<std::string, std::string> params;
  std::string url;
  if (!std::getline(iss, url, '?'))  // remove the URL part
  {
    cout<<"parsing url faield "<< param<<endl;
    return std::make_tuple(params, -11);
  }
  std::string keyval;
  std::string key;
  std::string val;

  while (std::getline(iss, keyval, '&'))  // split each term
  {
    std::istringstream iss(keyval);

    // split key/value pairs
    if (std::getline(std::getline(iss, key, '='), val)) {
      params[key] = val;
    }
  }
  return std::make_tuple(params, !params.empty() ? 0 : -12);
}

int main(){
  std::string params="?cloudgsid=cap-123&upstream=rtc";
  auto [param,retcode]=ParseUrl(params);
  if(retcode!=0){
    cout<<"retcode is not 0"<<endl;
  }else{
    for(const auto&v:param){
      cout<<v.first<<"="<<v.second<<endl;
    }
  }
  return 0;
}