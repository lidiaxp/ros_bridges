docker run -it --rm \
    --env="ROS_MASTER_URI=http://$(ip route | awk '/^default via/ {print $5}' | xargs -I {} ip addr show {} | awk '/inet / {split($2, a, "/"); print a[1]}'):11311" --env="DISPLAY=$DISPLAY" \
    --env="QT_X11_NO_MITSHM=1" \
    --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" \
    --env="XAUTHORITY=$XAUTH" \
    --volume="$XAUTH:$XAUTH" \
    --mount type=bind,source=$(pwd)/ros1_msgs_ws,target=/home/ros1_msgs_ws \
    --mount type=bind,source=$(pwd)/ros2_msgs_ws,target=/home/ros2_msgs_ws \
    --mount type=bind,source=$(pwd)/bridge.yaml,target=/home/bridge.yaml \
    --privileged \
    --net=host \
    --name=bridge_eloquent \
    bridge_eloquent
