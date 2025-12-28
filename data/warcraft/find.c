// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m哈雷摩托車[2;37;0m[2;37;0m", ({"motor"}));        
        set("gender", "男性");                
        set("long", "哈雷摩托是由哈雷戴維森摩托車公司生產的摩托車品牌。[2;37;0m
它是尋寶小娘的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "find");
        set("owner_name", "尋寶小娘");
        set_temp("owner", "find");
        set_temp("owner_name", "尋寶小娘");
        ::setup();
}
