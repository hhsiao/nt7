// check recruit

int permit_recruit(object ob)
{
        if( query("detach/密宗", ob) || query("betrayer/密宗", ob) )
        {
                command("say 你離開了密宗們，密宗已經不認你了！");
                return 0;
        }

        if( query("betrayer/times", ob) )
        {
                command("say 我們密宗最恨判師之徒，你還不快滾？");
                return 0;
        }

        if( query("family/family_name", ob) && 
            query("family/family_name", ob) != "密宗" )
        {
                command("say 你有師傅指點，當循序漸進，怎可貿然判師？");
                return 0;
        }

        return 1;
}
