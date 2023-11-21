# Dockerfile to bridge the ros1 and ros2 messages
#
# Build the ros1 messages
# ------------------------
FROM athackst/ros:melodic-dev as ros_builder

WORKDIR /workspaces/ros

RUN mkdir -p src && cd src \
 && git clone --branch kinetic https://github.com/athackst/aws_deepracer_msgs.git \
 && cd ../ \
 && catkin_make install -DCMAKE_INSTALL_PREFIX=/opt/ros/melodic

# Install catkin_tools and colcon
RUN apt-get update && apt-get install -y \
    python3-catkin-tools 

RUN apt install -y libopencv-dev curl
RUN apt install -y ros-melodic-image-transport
RUN apt install -y ros-melodic-tf
RUN apt install -y ros-melodic-tf2-geometry-msgs

WORKDIR /root
RUN mkdir -p /root/catkin_ws/src
WORKDIR /root/catkin_ws/src
RUN git clone https://github.com/appliedAI-Initiative/orb_slam_2_ros.git
RUN git clone --branch melodic https://github.com/ros-perception/vision_opencv.git
RUN apt install libeigen3-dev
WORKDIR /root/catkin_ws
RUN catkin build
# RUN source ~/catkin_ws/devel/setup.bash

#
# Build the ros2 messages
# ------------------------
FROM athackst/ros2:eloquent-dev as ros2_builder

WORKDIR /workspaces/ros2

RUN mkdir -p src && cd src \
 && git clone --branch eloquent https://github.com/athackst/aws_deepracer_msgs.git \
 && cd ../ \
 && colcon build --merge-install --install-base /opt/ros/eloquent

#
# Build the ros1_bridge
# -----------------------
FROM athackst/ros2:eloquent-dev as ros1_bridge_builder

# install melodic
RUN sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list' \
  && curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | apt-key add -
   
RUN apt-get update 
RUN apt-get install -y ros-melodic-ros-base 
RUN rm -rf /var/lib/apt/lists/*
 
#RUN sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list' \
#    && apt-get update \
#    && apt-get install -y curl \
#    && curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | apt-key add - \
#    && apt-get remove -y curl \
#    && apt-get update \
#    && apt-get install -y ros-melodic-ros-base \
#    && rm -rf /var/lib/apt/lists/*

  
#RUN curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | apt-key add -
#RUN sh -c 'echo "deb [arch=amd64,arm64] http://packages.ros.org/ros2/ubuntu focal main" > /etc/apt/sources.list.d/ros2-latest.list'
#RUN apt-get update && apt-get install -y \
#    ros-melodic-ros-base

# Get the ros messages
COPY --from=ros_builder /opt/ros/melodic /opt/ros/melodic
COPY --from=ros_builder /root/catkin_ws/src /root/catkin_ws/src

# Get the ros2 messages
COPY --from=ros2_builder /opt/ros/eloquent/ /opt/ros/eloquent

# Deps for the bridge
RUN apt-get update && apt-get install -y \
  # Test deps
  ros-eloquent-demo-nodes-cpp \
  ros-eloquent-launch-testing \
  ros-eloquent-launch-testing-ament-cmake \
  ros-eloquent-launch-testing-ros \
  ros-melodic-rospy-tutorials \
  ros-melodic-roscpp-tutorials \
  # Build deps
  libboost-filesystem-dev \
  libboost-math-dev \
  libboost-regex-dev \
  libboost-signals-dev \
  libboost-thread-dev \
  liblog4cxx-dev \
  && rm -rf /var/lib/apt/lists/*

# Set up the environment
ENV LD_LIBRARY_PATH=/opt/ros/eloquent/lib:/opt/ros/melodic/lib
ENV AMENT_PREFIX_PATH=/opt/ros/eloquent
ENV ROS_ETC_DIR=/opt/ros/melodic/etc/ros
ENV COLCON_PREFIX_PATH=/opt/ros/eloquent
ENV ROS_ROOT=/opt/ros/melodic/share/ros
ENV ROS_MASTER_URI=http://localhost:11311
ENV ROS_VERSION=2
ENV ROS_LOCALHOST_ONLY=0
ENV ROS_PYTHON_VERSION=3
ENV PYTHONPATH=/opt/ros/eloquent/lib/python3.6/site-packages:/opt/ros/melodic/lib/python2.7/dist-packages
ENV ROS_PACKAGE_PATH=/opt/ros/melodic/share
ENV ROSLISP_PACKAGE_DIRECTORIES=
ENV PATH=/opt/ros/eloquent/bin:/opt/ros/melodic/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
ENV PKG_CONFIG_PATH=/opt/ros/melodic/lib/pkgconfig
ENV CMAKE_PREFIX_PATH=/opt/ros/eloquent:/opt/ros/melodic

# Build the bridge
COPY ros1_bridge /home


WORKDIR /workspaces/ros1_bridge

RUN mkdir -p src && cd src \
&& git clone --branch main https://github.com/lidiaxp/ros1_bridge.git \
&& cd ../ \
&& colcon build --merge-install --packages-select ros1_bridge --cmake-force-configure --install-base /opt/ros/eloquent

#RUN mkdir -p src && cd src \
#&& git clone --branch eloquent_dev https://github.com/athackst/ros1_bridge.git \
#&& cd ../ \
#&& colcon build --merge-install --packages-select ros1_bridge --cmake-force-configure --install-base /opt/ros/eloquent

#RUN mkdir -p src && cd src && \
#    cp -r /home/ros1_bridge /workspaces/ros1_bridge/src && \
#    cd ../ && \
#    colcon build --merge-install --packages-select ros1_bridge --cmake-force-configure --install-base /opt/ros/eloquent


#
# Run the ros1_bridge
# ---------------------------
FROM athackst/ros2:eloquent-base

# install melodic
RUN sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list' \
  && curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | apt-key add -
   
RUN apt-get update 
RUN apt-get install -y ros-melodic-ros-base 
RUN rm -rf /var/lib/apt/lists/*
  
#RUN sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list' \
#    && apt-get update \
#    && apt-get install -y curl \
#    && curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | apt-key add - \
#    && apt-get remove -y curl \
#    && apt-get update \
#    && apt-get install -y ros-melodic-ros-base \
#    && rm -rf /var/lib/apt/lists/*


#RUN curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | apt-key add -
#RUN sh -c 'echo "deb [arch=amd64,arm64] http://packages.ros.org/ros2/ubuntu focal main" > /etc/apt/sources.list.d/ros2-latest.list'
#RUN apt-get update && apt-get install -y \
#    ros-melodic-ros-base

# Copy the ros outputs
COPY --from=ros1_bridge_builder /opt/ros/melodic /opt/ros/melodic

# Copy the ros2 outputs
COPY --from=ros1_bridge_builder /opt/ros/eloquent/ /opt/ros/eloquent

# Deps for the bridge
RUN apt-get update && apt-get install -y \
  tmux \
  git \
  # Test deps
  ros-eloquent-demo-nodes-cpp \
  ros-eloquent-launch-testing \
  ros-eloquent-launch-testing-ament-cmake \
  ros-eloquent-launch-testing-ros \
  ros-melodic-rospy-tutorials \
  ros-melodic-roscpp-tutorials \
  # Build deps
  libboost-filesystem-dev \
  libboost-math-dev \
  libboost-regex-dev \
  libboost-signals-dev \
  libboost-thread-dev \
  liblog4cxx-dev \
  && rm -rf /var/lib/apt/lists/*

# Set up the environment
ENV LD_LIBRARY_PATH=/opt/ros/eloquent/lib:/opt/ros/melodic/lib
ENV AMENT_PREFIX_PATH=/opt/ros/eloquent
ENV ROS_ETC_DIR=/opt/ros/melodic/etc/ros
ENV CMAKE_PREFIX_PATH=/opt/ros/melodic:/opt/ros/eloquent
ENV COLCON_PREFIX_PATH=/opt/ros/eloquent
ENV ROS_ROOT=/opt/ros/melodic/share/ros
ENV ROS_MASTER_URI=http://localhost:11311
ENV ROS_VERSION=1
ENV ROS_LOCALHOST_ONLY=0
ENV ROS_PYTHON_VERSION=2
ENV PYTHONPATH=/opt/ros/melodic/lib/python2.7/dist-packages:/opt/ros/eloquent/lib/python3.6/site-packages
ENV ROS_PACKAGE_PATH=/opt/ros/melodic/share
ENV ROSLISP_PACKAGE_DIRECTORIES=
ENV PATH=/opt/ros/melodic/bin:/opt/ros/eloquent/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
ENV PKG_CONFIG_PATH=/opt/ros/melodic/lib/pkgconfig

# Run the print-pairs command to check if things are working properly
RUN ros2 run ros1_bridge dynamic_bridge --print-pairs

RUN apt update && apt install -y python3-pip && pip3 install paho-mqtt

# Copy the start_bridge.sh script
COPY subs_pc_mqtt_ros1.py /root/subs_pc_mqtt_ros1.py
COPY check_collision.py /root/check_collision.py
COPY start_bridge.sh /root/start_bridge.sh
COPY out.sh /root/out.sh

# Set executable permissions for start_bridge.sh
RUN chmod +x /root/start_bridge.sh

RUN echo "alias out='bash /root/out.sh'" >> /root/.bashrc

# Set the start_bridge.sh script as the entrypoint
ENTRYPOINT ["/root/start_bridge.sh"]


# CMD ["bash", "-c", "ros2 run ros1_bridge dynamic_bridge --bridge-all-pairs"]

