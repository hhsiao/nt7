#!/bin/bash
# save as: start.sh

# Get the directory where this script is located
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

DRIVER="../fluffos/build/bin/driver"
CONFIG="config.ini"

echo "MUD Auto-Restart Script"
echo "======================="

while true; do
    echo ""
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] Starting driver..."
    
    # Run the driver
    $DRIVER $CONFIG
    
    # Capture exit code
    EXIT_CODE=$?
    
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] Driver exited with code: $EXIT_CODE"
    
    # Check exit code
    if [ $EXIT_CODE -eq 255 ]; then
        echo "[$(date '+%Y-%m-%d %H:%M:%S')] Reboot requested. Restarting in 3 seconds..."
        sleep 3
    elif [ $EXIT_CODE -eq 0 ]; then
        echo "[$(date '+%Y-%m-%d %H:%M:%S')] Normal shutdown. Exiting."
        break
    else
        echo "[$(date '+%Y-%m-%d %H:%M:%S')] Abnormal exit. Exiting."
        break
    fi
done

echo "[$(date '+%Y-%m-%d %H:%M:%S')] Script terminated."
