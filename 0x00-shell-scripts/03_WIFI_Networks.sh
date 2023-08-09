#!/bin/bash

# Get a list of available WiFi networks and their signal strengths
wifi_info=$(nmcli -f SSID,SIGNAL dev wifi list)

# Check if there are available networks
if [[ -z "$wifi_info" ]]; then
    echo "Can't recommend any WIFI network"
else
    # Remove any hidden networks and sort by signal strength
    recommended_network=$(echo "$wifi_info" | grep -v "^$" | sort -k2 -nr | head -n 1 |  awk '{print $1}' )
    if [[ -z "$recommended_network" ]]; then
        echo "Can't recommend any WIFI network"
    else
        echo "Recommended WIFI network: $recommended_network"
    fi
fi
