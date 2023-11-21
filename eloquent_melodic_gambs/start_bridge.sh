#!/bin/bash

# Start a new tmux session
tmux new-session -d -s mysession

# Create the first window and run roscore
tmux new-window -t mysession:1 -n 'roscore'
tmux send-keys -t mysession:1 'roscore' C-m

# Create the second window and run ros1_bridge
tmux new-window -t mysession:2 -n 'ros1_bridge'
tmux send-keys -t mysession:2 'ros2 run ros1_bridge dynamic_bridge --bridge-all-topics' C-m

# Attach to the session
tmux new-window -t mysession:3 -n 'test'
tmux attach-session -t mysession
