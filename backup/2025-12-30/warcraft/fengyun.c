// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m規規[2;37;0m[2;37;0m", ({"guigui"}));        
        set("gender", "女性");                
        set("long", "好大一隻鳥！！~~~~好大一隻鳥！！~~~~好大一隻鳥啊！！~~~~l[2;37;0m
它是胡不歸的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fengyun");
        set("owner_name", "胡不歸");
        set_temp("owner", "fengyun");
        set_temp("owner_name", "胡不歸");
        ::setup();
}
