// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m蛟[34m龍[2;37;0m[2;37;0m[2;37;0m", ({"gdragon"}));        
        set("gender", "男性");                
        set("long", "我的小寵物 ^_^[2;37;0m
它是不倒翁的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lohan");
        set("owner_name", "不倒翁");
        set_temp("owner", "lohan");
        set_temp("owner_name", "不倒翁");
        ::setup();
}
