module Main where

import qualified Prelude as P
import System.IO

import Zeldspar.Multicore


mainProgram :: Multicore ()
mainProgram = return ()

main = do
    let outFile = "gen/cipher.c"
    h <- openFile outFile WriteMode
    hPutStrLn h $ compile mainProgram
    hClose h
    putStrLn $ "PThread source generated: " P.++ show outFile

    let modules = compileAll `onParallella` mainProgram
    outFiles <- forM modules $ \(name, contents) -> do
        let name' = if name P.== "main" then "host" else name
            path  = "gen/" P.++ name' P.++ ".c"
        writeFile path contents
        return path
    putStrLn $ "Epiphany sources generated: " P.++ show outFiles
