#include <libremidi/libremidi.hpp>

#include <cstdlib>
#include <iostream>

int main(int argc, char**)
try
{
  libremidi::midi_in midiin{{
      // Set our callback function.
          .on_message = [](const libremidi::message& message) { if(message.size()>=3)std::cout << message.size() << std::endl; },

      // Don't ignore sysex, timing, or active sensing messages.
      .ignore_sysex = false,
      .ignore_timing = false,
      .ignore_sensing = false,
  }};

  auto ports = libremidi::observer{{}, observer_configuration_for(midiin.get_current_api())}
                     .get_input_ports();
  std::string portName;

  unsigned int nPorts = ports.size();
  if (nPorts >= 1) {
      midiin.open_port(ports[0]);
      portName = ports[0].display_name.empty()? ports[0].device_name : ports[0].display_name;
      std::cout << "PORT " << portName <<
          " connected : " << std::boolalpha << midiin.is_port_connected() <<
          " opened : " << midiin.is_port_open()<< std::endl;
  }
  if (portName.empty()){
      portName = "No MIDI Devices Found";
      return -1;
  }

  std::cout << "\nReading MIDI input ... play a note to see the error. press <enter> to quit.\n";
  char input;
  std::cin.get(input);
}
catch (const libremidi::midi_exception& error)
{
  std::cerr << error.what() << std::endl;
  return EXIT_FAILURE;
}
