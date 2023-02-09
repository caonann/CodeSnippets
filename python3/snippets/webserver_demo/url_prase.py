from urllib.parse import urlparse, parse_qs
#URL='https://someurl.com/with/query_string?i=main&mode=front&sid=12ab&enc=+Hello'
#URL='?cloudgsid=cap-123&upstream=rtc'
URL="bad url"
parsed_url = urlparse(URL)
ret = parse_qs(parsed_url.query)
print(ret)