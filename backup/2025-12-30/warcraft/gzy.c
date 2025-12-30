// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m純陽無極獸[2;37;0m[2;37;0m", ({"gzyds"}));        
        set("gender", "男性");                
        set("long", "一隻剛猛絕倫的麒麟，乃天生地化，日月之精華所成[2;37;0m
它是顧正陽的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "gzy");
        set("owner_name", "顧正陽");
        set_temp("owner", "gzy");
        set_temp("owner_name", "顧正陽");
        ::setup();
}
