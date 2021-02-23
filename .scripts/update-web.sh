#!/bin/sh

cd /www/R-mac-dev/.scripts
./mkweb && cp -p  web/index.html web/log-R-* ../
