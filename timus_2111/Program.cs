﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace timus_2111
{
    class Program
    {
        static void Main(string[] args)
        {
            new Program().Do(Console.In, Console.Out);
        }

        private void Do(TextReader input, TextWriter output)
        {
            input.ReadLine();
            var s = input.ReadLine();
            var p = s
                .Split(' ')
                .Select(s1 => int.Parse(s1))
                .OrderBy(i => i)
                .ToArray();

            int weight = 0;
            int nalog = 0;
            for (int i = 0; i < p.Length; ++i)
            {
                nalog += weight * p[i];
                weight += p[i];
                nalog += weight * p[i];
            }

            output.WriteLine(nalog.ToString());
        }
    }
}