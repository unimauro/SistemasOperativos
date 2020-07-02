#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os
import sys
import BaseHTTPServer

class RequestHandler (BaseHTTPServer.BaseHTTPRequestHandler):
    def do_GET (self):
        self.send_response(200)
        self.end_headers()
        self.wfile.write(self._get_status())
        return
    def _get_status (self):
        return "Status:\n" \
               "——-\n" \
               "Load average: %s\n" % \
               ("%01.2f, %01.2f, %01.2f" % \
                           os.getloadavg())            

def main (args):
    httpd = BaseHTTPServer.HTTPServer(('localhost', 7000), RequestHandler)
    httpd.serve_forever()

if __name__ == "__main__":
    sys.exit(main(sys.argv))
