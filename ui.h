#ifndef CREUI_UI_H
#define CREUI_UI_H

#include <map>
#include <vector>
#include <string>
#include <functional>

namespace cre
{
	class ui
	{
		protected:
			std::map<std::string, int> Parameters;
			class Help
			{
				public:
					std::string Format;
					va_list Args;
					Help()
						:Format(), Args()
					{
					}
			};
			std::vector<std::function<void()> > ToBeExecuted;
			virtual void between();//can be override!
			virtual int analyze(int Count, char ** Args);//can be override!Only deal with ONE enter! The loop is written in a higher layer. Need to return the number of args used.
			void wrongInput();
			void needHelp();
			void exit();
		public:
			int run(int Count, char ** Args);
			void setHelp(const char* Format, ...);
			void printHelp();
			template<class Fn, class... Args> void addExecutable(Fn&& fn, Args&&... args);
			ui();
			virtual ~ui();
		private:
			void set(int Count, char ** Args);
			int execute();
			Help TheHelp;
			bool WrongInput;
			bool Exit;
			bool NeedHelp;
	};
}

#endif
