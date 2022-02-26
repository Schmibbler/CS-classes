
public class TextAnalysis
{
    private String[] data;
    private int[] alphabet = new int[26];
    private int[] wordsize = new int[16];
    private int[] wordcount = new int[31];
    private int limit;
    
    public TextAnalysis (int limit, String [] data)
    {
        this.data = data;
        this.limit = limit;
    }
    
    
    public void display()
    {
        for (int i = 0; i < this.data.length; i++)
            System.out.println(this.data[i]);
        
    }
    
    public void tableDisplay()
    {
        char[] alphabet_array = "ABCDEFGHIJKLMNOPQRSTUVQWXYZ".toCharArray();
        
        
        System.out.println("Letter 	 Count");
        for (int i = 0; i < alphabet_array.length; i++)
            System.out.printf("%c        %d\n", alphabet_array[i], this.alphabet[i]);
        System.out.println("---------------------------------");
        
        System.out.println("Word Length 	Occurances");
        for (int i = 0; i < this.wordsize.length; i++)
            System.out.printf("%d                   %d\n", i+1, this.wordsize[i+1]);
        System.out.println("---------------------------------");
        
        System.out.println("Sentence Length 	Occurances");
        for (int i = 0; i < wordcount.length; i++)
            System.out.printf("%d                  %d", i+1, this.wordcount[i+1]);
        System.out.println("---------------------------------");
        
        
    }
    
    public void letterAnalysis()
    {
        
        for (int i = 0; i < this.limit; i++)
        {
            String test_str = new String(this.data[i]);
            for (int j = 0; j < test_str.length(); j++)
            {
                int char_as_index = (int)test_str.charAt(j) - 65;
                if (char_as_index < 0 || char_as_index > 25)
                    continue;
                else
                    this.alphabet[char_as_index]++;
                
            }
            
        }

    }
    
    public void wordAnalysis(int sentence_limit)
    {
        if (sentence_limit < 0 || sentence_limit > this.limit)
        {
            System.out.println("Exceed and cannot produce an analysis on this component");
            return;
        }
            
            
        for (int i = 0; i < sentence_limit; i++)
        {
            int word_count_per_sentence = 1;
            for (int j = 0; j < this.data[i].length(); i++)
            {
                if (this.data[i].charAt(j) == ' ')
                    word_count_per_sentence++;
                
            }
            this.wordcount[word_count_per_sentence - 1]++;
        }
        
        
    }
    
    public void wordAnalysis()
    {
            
            
        for (int i = 0; i < this.limit; i++)
        {
            int word_count_per_sentence = 1;
            for (int j = 0; j < this.data[i].length(); i++)
            {
                if (this.data[i].charAt(j) == ' ')
                    word_count_per_sentence++;
                
            }
            this.wordcount[word_count_per_sentence - 1]++;
        }
        
        
    }
    
    
    
    
}