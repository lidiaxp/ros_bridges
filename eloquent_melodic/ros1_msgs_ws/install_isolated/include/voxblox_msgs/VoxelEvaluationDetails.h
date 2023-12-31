// Generated by gencpp from file voxblox_msgs/VoxelEvaluationDetails.msg
// DO NOT EDIT!


#ifndef VOXBLOX_MSGS_MESSAGE_VOXELEVALUATIONDETAILS_H
#define VOXBLOX_MSGS_MESSAGE_VOXELEVALUATIONDETAILS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace voxblox_msgs
{
template <class ContainerAllocator>
struct VoxelEvaluationDetails_
{
  typedef VoxelEvaluationDetails_<ContainerAllocator> Type;

  VoxelEvaluationDetails_()
    : max_error(0.0)
    , min_error(0.0)
    , num_evaluated_voxels(0)
    , num_ignored_voxels(0)
    , num_overlapping_voxels(0)
    , num_non_overlapping_voxels(0)  {
    }
  VoxelEvaluationDetails_(const ContainerAllocator& _alloc)
    : max_error(0.0)
    , min_error(0.0)
    , num_evaluated_voxels(0)
    , num_ignored_voxels(0)
    , num_overlapping_voxels(0)
    , num_non_overlapping_voxels(0)  {
  (void)_alloc;
    }



   typedef double _max_error_type;
  _max_error_type max_error;

   typedef double _min_error_type;
  _min_error_type min_error;

   typedef uint32_t _num_evaluated_voxels_type;
  _num_evaluated_voxels_type num_evaluated_voxels;

   typedef uint32_t _num_ignored_voxels_type;
  _num_ignored_voxels_type num_ignored_voxels;

   typedef uint32_t _num_overlapping_voxels_type;
  _num_overlapping_voxels_type num_overlapping_voxels;

   typedef uint32_t _num_non_overlapping_voxels_type;
  _num_non_overlapping_voxels_type num_non_overlapping_voxels;





  typedef boost::shared_ptr< ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator> const> ConstPtr;

}; // struct VoxelEvaluationDetails_

typedef ::voxblox_msgs::VoxelEvaluationDetails_<std::allocator<void> > VoxelEvaluationDetails;

typedef boost::shared_ptr< ::voxblox_msgs::VoxelEvaluationDetails > VoxelEvaluationDetailsPtr;
typedef boost::shared_ptr< ::voxblox_msgs::VoxelEvaluationDetails const> VoxelEvaluationDetailsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator1> & lhs, const ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator2> & rhs)
{
  return lhs.max_error == rhs.max_error &&
    lhs.min_error == rhs.min_error &&
    lhs.num_evaluated_voxels == rhs.num_evaluated_voxels &&
    lhs.num_ignored_voxels == rhs.num_ignored_voxels &&
    lhs.num_overlapping_voxels == rhs.num_overlapping_voxels &&
    lhs.num_non_overlapping_voxels == rhs.num_non_overlapping_voxels;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator1> & lhs, const ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace voxblox_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ae63ff7a8fed6761c7b2408516d56b79";
  }

  static const char* value(const ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xae63ff7a8fed6761ULL;
  static const uint64_t static_value2 = 0xc7b2408516d56b79ULL;
};

template<class ContainerAllocator>
struct DataType< ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator> >
{
  static const char* value()
  {
    return "voxblox_msgs/VoxelEvaluationDetails";
  }

  static const char* value(const ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 max_error\n"
"float64 min_error\n"
"uint32 num_evaluated_voxels\n"
"uint32 num_ignored_voxels\n"
"uint32 num_overlapping_voxels\n"
"uint32 num_non_overlapping_voxels\n"
;
  }

  static const char* value(const ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.max_error);
      stream.next(m.min_error);
      stream.next(m.num_evaluated_voxels);
      stream.next(m.num_ignored_voxels);
      stream.next(m.num_overlapping_voxels);
      stream.next(m.num_non_overlapping_voxels);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct VoxelEvaluationDetails_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::voxblox_msgs::VoxelEvaluationDetails_<ContainerAllocator>& v)
  {
    s << indent << "max_error: ";
    Printer<double>::stream(s, indent + "  ", v.max_error);
    s << indent << "min_error: ";
    Printer<double>::stream(s, indent + "  ", v.min_error);
    s << indent << "num_evaluated_voxels: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.num_evaluated_voxels);
    s << indent << "num_ignored_voxels: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.num_ignored_voxels);
    s << indent << "num_overlapping_voxels: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.num_overlapping_voxels);
    s << indent << "num_non_overlapping_voxels: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.num_non_overlapping_voxels);
  }
};

} // namespace message_operations
} // namespace ros

#endif // VOXBLOX_MSGS_MESSAGE_VOXELEVALUATIONDETAILS_H
