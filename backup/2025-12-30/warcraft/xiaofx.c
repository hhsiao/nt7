// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m鳳仙[2;37;0m[2;37;0m", ({"xiaofxs"}));        
        set("gender", "男性");                
        set("long", "哈哈[2;37;0m
它是小鳳仙的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xiaofx");
        set("owner_name", "小鳳仙");
        set_temp("owner", "xiaofx");
        set_temp("owner_name", "小鳳仙");
        ::setup();
}
