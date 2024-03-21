CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

# Directorio para los archivos binarios
BINDIR = bin

# Nombre del ejecutable
EXECUTABLE = $(BINDIR)/sistemaFacturas

# Fuentes y objetos
SOURCES = $(wildcard Cliente/*.cpp) \
          $(wildcard Factura/*.cpp) \
          $(wildcard GestorFactura/*.cpp) \
          $(wildcard Item/*.cpp) \
          $(wildcard UI/*.cpp) \
          main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Crear el directorio bin
$(shell mkdir -p $(BINDIR))

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
