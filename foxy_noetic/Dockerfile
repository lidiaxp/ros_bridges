# Base image
FROM ubuntu:20.04

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive

# Install common dependencies
RUN apt-get update && apt-get install -y \
    curl \
    gnupg2 \
    lsb-release

# Install ROS Foxy
RUN curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | apt-key add -
RUN sh -c 'echo "deb [arch=amd64,arm64] http://packages.ros.org/ros2/ubuntu focal main" > /etc/apt/sources.list.d/ros2-latest.list'
RUN apt-get update && apt-get install -y \
    ros-foxy-desktop

# Install ROS Noetic
RUN sh -c 'echo "deb http://packages.ros.org/ros/ubuntu focal main" > /etc/apt/sources.list.d/ros-noetic.list'
RUN curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | apt-key add -
RUN apt-get update && apt-get install -y \
    ros-noetic-desktop

RUN apt install -y ros-foxy-ros1-bridge

# Install catkin_tools and colcon
RUN apt-get update && apt-get install -y \
    python3-catkin-tools \
    python3-colcon-common-extensions

# Install diagnostic_msgs package
RUN apt-get update && apt-get install -y \
    ros-foxy-diagnostic-msgs

# Clone and build ament_cmake from source
RUN apt-get update && apt-get install -y \
    git \
    build-essential \
    python3-rosdep \
    python3-rosinstall-generator \
    python3-vcstool
RUN mkdir -p /ament_ws/src && cd /ament_ws/src && \
    git clone https://github.com/ament/ament_cmake.git
RUN cd /ament_ws && \
    /bin/bash -c "source /opt/ros/foxy/setup.bash && \
    colcon build --symlink-install"

# Source ROS setup files
RUN echo "source /opt/ros/foxy/setup.bash" >> ~/.bashrc
RUN echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc

# Deps for the bridge
RUN apt-get update && apt-get install -y \
    tmux \
    git \
    # Test deps
    ros-foxy-demo-nodes-cpp \
    ros-foxy-launch-testing \
    ros-foxy-launch-testing-ament-cmake \
    ros-foxy-launch-testing-ros \
    ros-noetic-rospy-tutorials \
    ros-noetic-roscpp-tutorials \
    # Build deps
    libboost-filesystem-dev \
    libboost-math-dev \
    libboost-regex-dev \
    # libboost-signals-dev \
    libboost-thread-dev \
    liblog4cxx-dev \
    && rm -rf /var/lib/apt/lists/*

# Set up the environment
ENV LD_LIBRARY_PATH=/opt/ros/foxy/lib:/opt/ros/noetic/lib
ENV AMENT_PREFIX_PATH=/opt/ros/foxy
ENV ROS_ETC_DIR=/opt/ros/noetic/etc/ros
ENV COLCON_PREFIX_PATH=/opt/ros/foxy
ENV ROS_ROOT=/opt/ros/noetic/share/ros
ENV ROS_MASTER_URI=http://localhost:11311
ENV ROS_VERSION=2
ENV ROS_LOCALHOST_ONLY=0
ENV ROS_PYTHON_VERSION=3
ENV PYTHONPATH=/opt/ros/foxy/lib/python3.6/site-packages:/opt/ros/noetic/lib/python2.7/dist-packages
ENV ROS_PACKAGE_PATH=/opt/ros/noetic/share
ENV ROSLISP_PACKAGE_DIRECTORIES=
ENV PATH=/opt/ros/foxy/bin:/opt/ros/noetic/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
ENV PKG_CONFIG_PATH=/opt/ros/noetic/lib/pkgconfig
ENV CMAKE_PREFIX_PATH=/opt/ros/foxy:/opt/ros/noetic

# Build the bridge
# WORKDIR /catkin_ws_to_bridge
# RUN mkdir -p src && cd src 
# RUN git clone --branch melodic-devel https://github.com/ros-industrial-consortium/descartes.git
# RUN git clone --branch kinetic-devel https://github.com/ros-industrial/universal_robot.git
# RUN git clone --branch master https://github.com/ros-industrial/fake_ar_publisher.git
# RUN catkin build

COPY start_bridge.sh /root/start_bridge.sh
COPY out.sh /root/out.sh

RUN echo "alias out='bash /root/out.sh'" >> /root/.bashrc

RUN chmod +x /root/start_bridge.sh

ENTRYPOINT ["/root/start_bridge.sh"]
