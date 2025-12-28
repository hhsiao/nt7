// check recruit

int permit_recruit(object ob)
{
        if( query("detach/密宗", ob) || query("betrayer/密宗", ob) )
        {
                command("say 你離開了密宗們，就別回來！");
                return 0;
        }

        if( query("betrayer/times", ob) )
        {
                command("say 判師之徒，哼！哼！我把你千刀萬剮！");
                return 0;
        }

        if( query("family/family_name", ob) && 
            query("family/family_name", ob) != "密宗" )
        {
                command("say 你不是已經有了師傅麼，還來幹什麼？偷學我派秘技啊！");
                return 0;
        }

        return 1;
}
