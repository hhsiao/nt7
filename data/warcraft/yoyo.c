// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m靈魂[1;37m坐騎[2;37;0m[2;37;0m", ({"yoku"}));        
        set("gender", "男性");                
        set("long", "一匹來自遠古....[2;37;0m
它是楊逍遙的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "yoyo");
        set("owner_name", "楊逍遙");
        set_temp("owner", "yoyo");
        set_temp("owner_name", "楊逍遙");
        ::setup();
}
