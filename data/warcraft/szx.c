// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m烏騅[2;37;0m[2;37;0m", ({"wuzhui"}));        
        set("gender", "女性");                
        set("long", "烏騅馬出自於《西漢演義》中霸項羽的坐騎[2;37;0m
它是項羽的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "szx");
        set("owner_name", "項羽");
        set_temp("owner", "szx");
        set_temp("owner_name", "項羽");
        ::setup();
}
