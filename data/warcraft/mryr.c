// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[36m避水金睛獸[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "女性");                
        set("long", "它有一雙金色的瞳眸，眸中波光呈琉璃之色，看去似還有佛光湧現[2;37;0m
它是慕容雲染的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "mryr");
        set("owner_name", "慕容雲染");
        set_temp("owner", "mryr");
        set_temp("owner_name", "慕容雲染");
        ::setup();
}
