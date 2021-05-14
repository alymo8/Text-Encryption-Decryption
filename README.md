# Text-Encryption-Decryption
A Rail-Fence text cipher

This text cipher encrypts messages using a zig-zag pattern, known as rail-fence cipher. It gets as input a key, and puts the words in zig-zag in a puzzle as in the next picture.  
We can see how the message THISISASECRETMESSAGE, given with key 5, is put into that 2-D matrix and is then encrypted by the message TESHSCSAIAREGSSEMEIT.

![Screenshot (368)](https://user-images.githubusercontent.com/76274266/118340056-4cafbb00-b523-11eb-8067-4b92bc361da0.png)

the encryption basically involves sequentially producing the characters from each level, starting from the top
to the bottom, to the output. For the above example, the encryption produced will be TESHSCSAIAREGSSEMEIT. Where TES is from the first level, HSCSA is from the second level, and so forth.


If we try to  change the key, we get another output. Here is the encrypted message with key 3: TIETSHSSSCEMSAEIAREG.

![Screenshot (369)](https://user-images.githubusercontent.com/76274266/118340298-f55e1a80-b523-11eb-951e-5cf7fd356c4a.png)

The message that was sent can also be decrypted if the user has the encryption key. The decryption works in the same way, the matrix is reconstructed then we get the elements from it in the zig-zag way (and not in the horizontal way as in encryption). Here are some examples I used to test my code in Unix using the test file testcipher2.sh:

Here are examples of encryption and decryption for messages:

![Screenshot (375)](https://user-images.githubusercontent.com/76274266/118341084-87672280-b526-11eb-873b-00841525898a.png)

Here we are sending a normal text message, and it is being encrypted, we decrypt it later on by giving the correct key to the message, and get the original message back. This concept is the same idea as message encryption in social media applications, where only the sender and the receiver have the key to the encrypted message.

![Screenshot (374)](https://user-images.githubusercontent.com/76274266/118341202-ddd46100-b526-11eb-8faf-c3c8a8d2b838.png)
