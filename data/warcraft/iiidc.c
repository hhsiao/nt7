// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m蘿[1;33m拉[2;37;0m[2;37;0m", ({"baidu"}));        
        set("gender", "女性");                
        set("long", "網絡紅人  國寶級美女[2;37;0m
它是晚靜的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "iiidc");
        set("owner_name", "晚靜");
        set_temp("owner", "iiidc");
        set_temp("owner_name", "晚靜");
        ::setup();
}
