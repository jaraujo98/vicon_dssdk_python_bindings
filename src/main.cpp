#include <pybind11/pybind11.h>

#include "DataStreamClient.h"

#include <string>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;
namespace ds = ViconDataStreamSDK::CPP;

using namespace ViconDataStreamSDK::CPP;

PYBIND11_MODULE(vicon_dssdk, m)
{
    m.doc() = R"pbdoc(
        Bindings for the Vicon DataStream SDK
        -----------------------

        .. currentmodule:: vicon_dssdk

        .. autosummary::
           :toctree: _generate

           DataStreamClient
           Result
           Output_SimpleResult
           Output_Connect
    )pbdoc";

    // Client

    py::class_<ds::Client>(m, "DataStreamClient")
        .def(py::init<>())
        .def("connect", [](ds::Client &client, const std::string &host)
             {
        const ds::String host_str = ds::String(host);
        return client.Connect(host_str); }, R"pbdoc(
            Connect to the Vicon DataStream SDK
        )pbdoc")
        .def("get_frame", &ds::Client::GetFrame, R"pbdoc(
            Get a frame of data from the Vicon DataStream SDK
        )pbdoc");

    // Data types

    py::enum_<ds::Result::Enum>(m, "Result")
        .value("Unknown", ds::Result::Enum::Unknown)
        .value("NotImplemented", ds::Result::Enum::NotImplemented)
        .value("Success", ds::Result::Enum::Success)
        .value("InvalidHostName", ds::Result::Enum::InvalidHostName)
        .value("InvalidMulticastIP", ds::Result::Enum::InvalidMulticastIP)
        .value("ClientAlreadyConnected", ds::Result::Enum::ClientAlreadyConnected)
        .value("ClientConnectionFailed", ds::Result::Enum::ClientConnectionFailed)
        .value("ServerAlreadyTransmittingMulticast", ds::Result::Enum::ServerAlreadyTransmittingMulticast)
        .value("ServerNotTransmittingMulticast", ds::Result::Enum::ServerNotTransmittingMulticast)
        .value("NotConnected", ds::Result::Enum::NotConnected)
        .value("NoFrame", ds::Result::Enum::NoFrame)
        .value("InvalidIndex", ds::Result::Enum::InvalidIndex)
        .value("InvalidCameraName", ds::Result::Enum::InvalidCameraName)
        .value("InvalidSubjectName", ds::Result::Enum::InvalidSubjectName)
        .value("InvalidSegmentName", ds::Result::Enum::InvalidSegmentName)
        .value("InvalidMarkerName", ds::Result::Enum::InvalidMarkerName)
        .value("InvalidDeviceName", ds::Result::Enum::InvalidDeviceName)
        .value("InvalidDeviceOutputName", ds::Result::Enum::InvalidDeviceOutputName)
        .value("InvalidLatencySampleName", ds::Result::Enum::InvalidLatencySampleName)
        .value("CoLinearAxes", ds::Result::Enum::CoLinearAxes)
        .value("LeftHandedAxes", ds::Result::Enum::LeftHandedAxes)
        .value("HapticAlreadySet", ds::Result::Enum::HapticAlreadySet)
        .value("EarlyDataRequested", ds::Result::Enum::EarlyDataRequested)
        .value("LateDataRequested", ds::Result::Enum::LateDataRequested)
        .value("InvalidOperation", ds::Result::Enum::InvalidOperation)
        .value("NotSupported", ds::Result::Enum::NotSupported)
        .value("ConfigurationFailed", ds::Result::Enum::ConfigurationFailed)
        .value("NotPresent", ds::Result::Enum::NotPresent)
        .value("ArgumentOutOfRange", ds::Result::Enum::ArgumentOutOfRange)
        .export_values();

    py::class_<ds::Output_SimpleResult>(m, "Output_SimpleResult")
        .def(py::init<>())
        .def_readwrite("Result", &ds::Output_SimpleResult::Result);

    py::class_<ds::Output_Connect, ds::Output_SimpleResult>(m, "Output_Connect")
        .def(py::init<>());

    py::class_<ds::Output_GetFrame, ds::Output_SimpleResult>(m, "Output_GetFrame")
        .def(py::init<>());

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
