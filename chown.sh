#!/bin/sh
su -c chown -R u0_a227:u0_a227 $(pwd)
rm -f $(find $(pwd) -name "*.bak")
