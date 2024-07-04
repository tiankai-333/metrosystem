#include <iostream>
#include <vector>
#include"UserInterface.h"
using namespace std;
int main() {

    // 创建地铁系统实例
    MetroSystem metroSystem;
    //线路和换乘信息的存储与读取
    //系统必须具备将所有线路信息、站点间的时间权重以及换乘站的时间权重保存到文件的能力。
    //当程序下次启动时，系统应能够从文件中读取并恢复这些信息，确保用户能够继续使用之前设置的线路和权重信息。
    
    // 创建用户界面实例，并将地铁系统实例传递给它
    // 用户界面应提供直观的输入选项，使用户能够轻松设置和修改时间权重。
    // 界面应清晰展示路线查询的条件选择（时间最短或换乘最少），并能够展示查询结果的路线列表。
    //系统应具备良好的数据结构设计，以支持高效的数据存储和查询操作。
   

    //
    //
    UserInterface ui(metroSystem);
    int choice = 0;
    while(true)
    {
        ui.DisplayMainMenu();
        cout << "请输入您的选择：" << endl;
        cin >> choice;
    //退出系统
    if (choice == 0)

    //(1)输入线路信息
    if (choice == 1)
        //第一行输入地铁编号和站点个数n
        //例如，输入 "9 35" 表示地铁9号线共有35个站点，站点编号从1至35。
        cout<<"请输入地铁线路编号和站点个数："<<endl;
        metroSystem.AddMetroLine(ui.InputLineInfo());
        //第二行输入n个站点名
        //例如，输入35个站点名称，“songjiangnanzhan zuibaichi songjiangtiyuzhongxin songjiangxincheng songjiangdaxuecheng ……”。说明：这里输入的是拼音，可以考虑输入中文，这样更直观。
        cout<<"请输入站点名："<<endl;
        metroSystem.ExpandRoute(ui.InputLineInfo());

    //(2)输入换乘站信息
    if (choice == 2)
        cout<<"请输入换乘站信息："<<endl;
        //两种输入方式
        //输入地铁线路、地铁站点编号 int int
        //例如，输入 "3 5 9 16" 表示地铁3号线的第5站与地铁9号线的第16站之间可以进行换乘。
        //输入地铁线路、地铁站点名 int string
        //例如，输入“3 yishanlu 9 yishanlu”,表示地铁3号线的yishanlu与9号线的yishanlu之间可以换乘。
        metroSystem.AddTransferStation(ui.InputTransferStationInfo());

    //(3)线路信息修改
    if (choice == 3)
        cout<<"请输入线路信息修改："<<endl;

        //扩充线路长度
            
        //插入换乘站

        //删除换乘站
        //例如删除9号线和3号线的yishanlu站的换乘。

        //封闭线路区间
        //例如，封闭9号线的第16站至第18站，使得这三站无法出入或进行换乘。
    
        //恢复线路区间
    
    //(4)线路查询功能
    //输入线路号查询：例如，输入9，可以输出9号线的站点以及换乘信息。
    if (choice == 4)
        cout<<"请输入查询线路："<<endl;
    //(5)路线查询功能
    //输入起始站点查询     
    //例如，输入“songjiangdaxuecheng shijidadao”
    if (choice == 5)
        cout<<"请输入起始站点查询："<<endl;   

    //输出查询结果 
        //无需换乘则输出路线和起止站点。，
        //例如输出“乘坐9号线 songjiangdaxuecheng上车， shijidadao下车”
        
        //换乘路线所有必要的换乘站点和线路。
        //例如，输出“9号线 songjiangdaxuecheng上， yishanlu下\n3号线yishanlu上，zhongshangongyuan下”以及“9号线 songjiangdaxuecheng上， yishanlu下\n4号线yishanlu上，zhongshangongyuan下”
        
        //不可到达，如果站点暂时封闭或者不存在等情况则不可到达。
        
        //如果多条路线均最短，则都输出。
            //例如，3号和4号线都可以到达zhongshangongyuan，因此输出了两条路线。

    //允许用户选择查询时间最短或换乘次数最少的条件来查询路线。

    //(6)设置相邻站点之间的时间权重
    //系统应具备错误处理机制，能够处理用户输入错误或不合理的请求。例如要设置9号线第18站到第20站的行程需要5个单位时间，则需提示错误，因为仅能设置相邻站的权重。
    if (choice == 6)
        cout<<"请输入设置相邻站点之间的时间权重："<<endl;

    //（7）设置换乘站的时间权重
    //如 "3 5 9 16 8"，表示从地铁3号线的第5站换乘到地铁9号线的第16站需要8个单位时间。
    if (choice == 7)
        cout<<"请输入设置换乘站的时间权重："<<endl;
    
    // 输入有误的情况
    else 
        {  
            cout << "输入有误，请重新输入！" << endl;
            system("pause");
            system("cls");
        }
    }





}

/*1) 线路信息输入
   - 用户能够输入地铁线路编号和站点信息。
   - 例如，第一行输入 "9 35" 表示地铁9号线共有35个站点，站点编号从1至35。第二行输入35个站点名称“songjiangnanzhan zuibaichi songjiangtiyuzhongxin songjiangxincheng songjiangdaxuecheng ……”。说明：这里输入的是拼音，可以考虑输入中文，这样更直观。
   2) 换乘站信息输入
   - 用户能够输入换乘站信息。
   - 例如，输入 "3 5 9 16" 表示地铁3号线的第5站与地铁9号线的第16站之间可以进行换乘。也可输入“3 yishanlu 9 yishanlu”,表示地铁3号线的yishanlu与9号线的yishanlu之间可以换乘。
   3) 线路信息修改
   - 系统应支持以下修改操作：
     - 扩充线路长度：例如，将9号线的站点数量从35增加到40。
     - 缩短线路长度：例如，将9号线的站点数量从35减少到30。
     - 删除换乘站：允许用户删除指定线路间的换乘关系，例如删除9号线和3号线的yishanlu站的换乘。
     - 封闭线路区间：例如，封闭9号线的第16站至第18站，使得这三站无法出入或进行换乘。
     - 恢复线路区间：例如，恢复9号线的第16站
   4) 线路查询功能
     - 输入线路号查询：例如，输入9，可以输出9号线的站点以及换乘信息。
   5) 路线查询功能
   - 以上线路信息中，每两站之间距离均为1，所有换乘距离均为0。用户可以查询从某一站点到另一站点的最短路线。系统将输出以下结果之一：
     - 无需换乘则输出路线和起止站点。例如，输入“songjiangdaxuecheng shijidadao”，则输出“乘坐9号线 songjiangdaxuecheng上车， shijidadao下车”
     - 换乘路线所有必要的换乘站点和线路。例如，输入“songjiangdaxuecheng zhongshangongyuan”，则输出“9号线 songjiangdaxuecheng上， yishanlu下\n3号线yishanlu上，zhongshangongyuan下”以及“9号线 songjiangdaxuecheng上， yishanlu下\n4号线yishanlu上，zhongshangongyuan下”
     - 不可到达，如果站点暂时封闭或者不存在等情况则不可到达。
     - 如果多条路线均最短，则都输出。如上例，3号和4号线都可以到达zhongshangongyuan，因此输出了两条路线。
   6) 用户界面
   - 系统应提供一个简洁直观的菜单，使用户能够轻松输入、修改和查询地铁线路信息。
3.3. 进阶功能
   1) 时间权重设置
     - 系统应支持为地铁线路的各站之间以及换乘站设置时间权重。
     - 输入线路信息时，各站点间的默认时间权重为1单位时间。用户可以修改特定站点间的时间权重。例如，输入 "9 16 17 3" 表示地铁9号线从第16站到第17站的行程需要3个单位时间，其中的站点编号也可以用站名代替，例如输入“9 yishanlu xujiahui 3”表示9号线从yishanlu到xujiahui需要3个单位时间。下同。
     - 用户可以通过输入特定的格式来设置换乘站的时间权重，如 "3 5 9 16 8"，表示从地铁3号线的第5站换乘到地铁9号线的第16站需要8个单位时间。
   2) 多条件路线查询
     - 允许用户选择查询时间最短或换乘次数最少的条件来查询路线。
     - 系统将根据用户选择的条件提供最多3条最优路线。
   3) 线路和换乘信息的存储与读取
     - 系统必须具备将所有线路信息、站点间的时间权重以及换乘站的时间权重保存到文件的能力。
     - 当程序下次启动时，系统应能够从文件中读取并恢复这些信息，确保用户能够继续使用之前设置的线路和权重信息。
   4) 用户界面增强
     - 用户界面应提供直观的输入选项，使用户能够轻松设置和修改时间权重。
     - 界面应清晰展示路线查询的条件选择（时间最短或换乘最少），并能够展示查询结果的路线列表。
3.4. 技术要求
   - 系统应具备良好的数据结构设计，以支持高效的数据存储和查询操作。
   - 系统应具备错误处理机制，能够处理用户输入错误或不合理的请求。例如要设置9号线第18站到第20站的行程需要5个单位时间，则需提示错误，因为仅能设置相邻站的权重。
*/
