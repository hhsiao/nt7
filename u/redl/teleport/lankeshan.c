// This program is a part of NITAN MudLIB  
// redl 2014/8
#include <ansi.h>  
#include <room.h>  
inherit __DIR__"normal.c";  

void create()
{
        set("short","天生石樑");
        set("long", @LONG
這裡是爛柯山頂峰。左方有座石亭橫書“日遲亭”，右邊二人高
的石碑上面豎刻著“青霞第八洞天”。正前方有道拱如虯龍的天生石
梁，東西寬約十丈，彩虹一樣高高架起，形成了個方圓百米的洞窟。
洞裡幽風陣陣，清涼無比，確實是個參禪打坐的絕佳去處。
LONG );
        set("outdoors", "yangzhou");
        set("exits",([ /* sizeof() == 1 */
            "out"  : "/u/redl/teleport/teleport",
        ]));

        set("no_dazuo",1);
        set("no_kill",1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);         
        set("no_rideto", 1);
        set("no_flyto", 1);
        set("no_magic", 1); 
        set("no_user_kill", 1); 
        set("no_sleep_room", 1);  
        setup();
}

int do_sit() 
{
        object me = this_player(); 
        string file = "/temp/qroom/" + query("id", me) + ".c";
                if (!sizeof(get_dir("/temp/qroom"))) mkdir("/temp/qroom");
        set_temp("time_enter_qroom", time() + 10, me);
        if (!(load_object(file))) 
        cp("/u/redl/teleport/qroom.c", file);
        tell_object(me, NOR CYN "你隨意找了顆棋子盤腿一坐，眨眼就變幻了空間。\n" NOR); 
        me->move(file);
        return 1;
}


void init()  
{
        object me = this_player(); 
        if (query_temp("time_enter_qroom", me) < time()) {
                tell_object(me, NOR "你望著洞裡阡陌縱橫的棋盤，禁不住想找一顆棋子坐(" CYN "sit" NOR ")上去。\n" NOR); 
                add_action("do_sit","sit");  
        } else tell_object(me, NOR "你進出過於頻繁，望著阡陌棋盤，似乎忘記了去處。\n" NOR); 
}  






