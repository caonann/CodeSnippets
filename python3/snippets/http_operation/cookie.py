from http.cookies import SimpleCookie

rawdata = "pgv_pvid=1099042646; _ga=GA1.2.971559234.1657098671; _ga_6WSZ0YS5ZQ=GS1.1.1657105754.2.1.1657108237.0; _gcl_au=1.1.848503338.1673246788; sensorsdata2015jssdkcross=%7B%22distinct_id%22%3A%22546314485%22%2C%22first_id%22%3A%22181d2c7147b2cf-03463bb2be54fb6-1c525635-1484784-181d2c7147c1d06%22%2C%22props%22%3A%7B%22%24latest_traffic_source_type%22%3A%22%E5%BC%95%E8%8D%90%E6%B5%81%E9%87%8F%22%2C%22%24latest_search_keyword%22%3A%22%E6%9C%AA%E5%8F%96%E5%88%B0%E5%80%BC%22%2C%22%24latest_referrer%22%3A%22https%3A%2F%2Fdnspod.qcloud.com%2F%22%7D%2C%22identities%22%3A%22eyIkaWRlbnRpdHlfY29va2llX2lkIjoiMTgxZDJjNzE0N2IyY2YtMDM0NjNiYjJiZTU0ZmI2LTFjNTI1NjM1LTE0ODQ3ODQtMTgxZDJjNzE0N2MxZDA2IiwiJGlkZW50aXR5X2xvZ2luX2lkIjoiNTQ2MzE0NDg1In0%3D%22%2C%22history_login_id%22%3A%7B%22name%22%3A%22%24identity_login_id%22%2C%22value%22%3A%22546314485%22%7D%2C%22%24device_id%22%3A%22181d2c7147b2cf-03463bb2be54fb6-1c525635-1484784-181d2c7147c1d06%22%7D; x_host_key_access=a653a39e376eeb1d686a4dde72e086b626cf83fe_s; x-client-ssid=1863569eae7-e7fa3f437560924901f17d2f34b8c6c36b42e1d0; id_token=eyJhbGciOiJSUzI1NiIsInR5cCI6IkpXVCJ9.eyJleHAiOjE2NzY0NDU5MjEsImlhdCI6MTY3NjM1OTUyMSwianRpIjoieEM2YzBZSTZsaW1rWnVILWp6TGdQQSIsIm5iZiI6MTY3NjM1OTUyMSwidXNlcl9pZCI6NiwidXNlcl91dWlkIjoidG9mNF83OTg4NyIsInVzZXJuYW1lIjoiaHVsa2NhbyJ9.lzkI-AEYkGt7owOaVcEFFKQvqCfIrJM_nI6TZ_gBLPI2laiI40JMIyrXIbphd_VYEEmDV35Y_5pxxBn9YCnyiacz7XLNCuimFmxxKOWst3Wcq-Uplr6ktY_9MFGn9rwUb15WKflpDmzU8aZzd1bW6N18sCBsFxwT5Pd87HT_UKiIDiLWtOpIJVx0jFh1maWJyNILVde104dvazNSdZD1nzB9Xbl1jsg07pQsWaADuledYFqmhnLLR-vbCn45xqE9uG7ajncTgMj-LzrL9UKIdmzqkWBnSe9oy7UTH38paGuVY8CojYoyiykrnwJ7NCtC0o0lxYdCAnhrZFX6W3mIuQ"

cookie = SimpleCookie()
cookie.load(rawdata)
cookies = {}
for key, morsel in cookie.items():
    cookies[key] = morsel.value
print(cookies)
