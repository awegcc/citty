
.PHONY: all
all: citty

citty: main.cpp connectionNotebook.cpp sessionNotebook.cpp cittyFrame.cpp settingsPanel.cpp
	$(CXX) `wx-config --cxxflags --libs core base aui` -o citty main.cpp connectionNotebook.cpp sessionNotebook.cpp cittyFrame.cpp settingsPanel.cpp

.PHONY: clean
clean:
	rm -f citty *.o
